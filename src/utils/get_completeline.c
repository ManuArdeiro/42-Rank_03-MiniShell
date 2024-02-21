/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_completeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:08:48 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/21 19:02:49 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static void	ft_manage_fd(int *fd, int *pip, t_global *global, t_bool flag)
{
	if (flag == COPY)
	{
		*fd = dup(pip[0]);
		ft_closepipe(&pip[0], &pip[1]);
		g_exit_status = global->laststatus;
	}
	else if (flag == CLOSE)
	{
		if (*fd >= 0)
			close(*fd);
	}
}

static char	*ft_extract_line(int *pip, pid_t pid, t_global *global)
{
	char	*line;
	char	*buffer;
	int		fd;

	ft_manage_fd(&fd, pip, global, COPY);
	ft_wait_process(&pid, &global->laststatus, FORK, global);
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
	ft_manage_fd(&fd, pip, global, CLOSE);
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
