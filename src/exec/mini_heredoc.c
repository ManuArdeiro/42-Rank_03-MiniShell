/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:28:55 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/27 19:09:12 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_get_inputline(char **line, int *herepipe)
{
	*line = get_next_line(STDIN_FILENO);
	if (!line)
	{
		ft_closepipe(&herepipe[0], &herepipe[1]);
		ft_printerror(__func__, "Get next line");
		exit(EXIT_FAILURE);
	}
}

static void	ft_evaluate_line(
		char *cleanline,
		const char *delimiter, char *line, int *herepipe
)
{
	if (ft_strequal_cs(cleanline, delimiter) == TRUE)
	{
		free(line);
		free(cleanline);
		ft_closepipe(&herepipe[0], &herepipe[1]);
		exit(EXIT_SUCCESS);
	}
}

void	ft_writetofile(
	const char *delimiter, int *herepipe, t_global *global)
{
	char	*line;
	char	*cleanline;

	line = "";
	cleanline = NULL;
	global->signallist.sa_handler = &handle_sigint_exit;
	sigaction(SIGINT, &global->signallist, NULL);
	while (line != NULL)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		ft_get_inputline(&line, herepipe);
		cleanline = ft_strtrim(line, "\n");
		ft_evaluate_line(cleanline, delimiter, line, herepipe);
		ft_putstr_fd(line, herepipe[1]);
		free(line);
		free(cleanline);
	}
	exit(EXIT_SUCCESS);
}

void	ft_get_heredoc(t_file **file, t_global *global)
{
	int		herepipe[2];
	pid_t	child;

	if (pipe(herepipe) < 0)
		ft_printerror(__func__, "Pipe");
	global->signallist.sa_handler = SIG_IGN;
	sigaction(SIGINT, &global->signallist, NULL);
	child = fork();
	if (child == 0)
		ft_writetofile((*file)->name, herepipe, global);
	else if (child < 0)
		ft_printerror(__func__, "Fork");
	else
		ft_wait_close_heredoc(child, *file, herepipe, global);
}
