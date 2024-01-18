/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_completeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:08:48 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/17 19:53:18 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	ft_loop_end(const char *line, const char *prompt)
{
	if ((ft_strequal(prompt, PIPELINE) == TRUE
			&& ft_strlen(line) > 0 && line[0] != '\n' && line[0] != '|')
		|| (ft_strequal(prompt, BACKSLASH) == TRUE
			&& line != NULL && line[0] != '\\'))
		return (TRUE);
	return (FALSE);
}

static char	*ft_completeline(
		const char *commandline, const char *prompt, int pip[2])
{
	char	*line;
	char	*buffer;
	char	*result;

	buffer = NULL;
	result = NULL;
	line = "";
	if (commandline == NULL || prompt == NULL)
		return (NULL);
	buffer = ft_strdup(commandline);
	while (line != NULL)
	{
		ft_putstr_fd(prompt, STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
		{
			ft_closepipe(&pip[0], &pip[1]);
			ft_printerror(__func__, "Get next line");
			exit(EXIT_FAILURE);
		}
		else
			buffer = ft_strjoin_get(buffer, line);
		if (ft_loop_end(line, prompt) == TRUE)
			break ;
		free(line);
	}
	result = ft_strclean_withspaces(buffer, CLEAN_ALL_LEAVE_PIPE);
	free(buffer);
	return (result);
}

static void	ft_runchild(
		const char *commandline, t_global *global, int pip[2])
{
	char	*completeline;

	completeline = NULL;
	global->signallist.sa_handler = &handle_sigint_exit;
	sigaction(SIGINT, &global->signallist, NULL);
	if (ft_endswith(commandline, "\\") == TRUE)
		completeline = ft_completeline(commandline, BACKSLASH, pip);
	else if (ft_endswith(commandline, "|") == TRUE)
		completeline = ft_completeline(commandline, PIPELINE, pip);
	if (completeline)
	{
		free((char *)commandline);
		ft_putstr_fd(completeline, pip[1]);
		free(completeline);
	}
	else
		ft_putstr_fd(commandline, pip[1]);
	ft_closepipe(&pip[0], &pip[1]);
	exit(EXIT_SUCCESS);
}

static char	*ft_extract_line(int *pip, pid_t pid, t_global *global)
{
	char	*line;
	char	*buffer;
	int		fd;

	fd = -1;
	fd = dup(pip[0]);
	ft_closepipe(&pip[0], &pip[1]);
	ft_wait_process(&pid, &global->laststatus, FORK, global);
	g_exit_status = global->laststatus;
	if (fd >= 0)
		close(fd);
	line = "";
	buffer = NULL;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			buffer = ft_strjoin_get(buffer, line);
			free(line);
		}
	}
	if (g_exit_status != EXIT_SUCCESS)
	{
		free(buffer);
		return (ft_strdup(""));
	}
	return (buffer);
}

char	*ft_get_completeline(const char *commandline, t_global *global)
{
	char	*completeline;
	int		pip[2];
	pid_t	pid;

	completeline = NULL;
	if (commandline == NULL)
		return (NULL);
	if ((ft_countalpha(commandline) <= 1 && commandline[0] != '\\')
		|| (ft_endswith(commandline, "\\") == FALSE
			&& ft_endswith(commandline, "|") == FALSE))
		return ((char *)commandline);
	if (pipe(pip) < 0)
		ft_printerror(__func__, "pipe");
	global->signallist.sa_handler = SIG_IGN;
	sigaction(SIGINT, &global->signallist, NULL);
	pid = fork();
	if (pid == 0)
		ft_runchild(commandline, global, pip);
	else if (pid < 0)
		ft_printerror(__func__, "fork");
	else
		completeline = ft_extract_line(pip, pid, global);
	if (completeline == NULL)
		return ((char *)commandline);
	return (completeline);
}
