/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:28:55 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/24 19:08:23 by Ardeiro          ###   ########.fr       */
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

static void	ft_evaluate_line(const char *delimiter, char *line,
	int *herepipe, t_global *global)
{
	char	*cleanline;

	cleanline = NULL;
	cleanline = ft_strtrim(line, "\n");
	if (ft_strequal(cleanline, delimiter) == TRUE)
	{
		free(line);
		free(cleanline);
		ft_closepipe(&herepipe[0], &herepipe[1]);
		exit(EXIT_SUCCESS);
	}
	else if (global->sig_exit_status == 1)
	{
		free(line);
		free(cleanline);
		ft_closepipe(&herepipe[0], &herepipe[1]);
		exit(EXIT_FAILURE);
	}
}

void	ft_writetofile(const char *delimiter, int *herepipe, t_global *global)
{
	char	*line;

	line = "";
	while (line != NULL)
	{
		ft_signals(global);
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		ft_get_inputline(&line, herepipe);
		ft_evaluate_line(delimiter, line, herepipe, global);
		ft_putstr_fd(line, herepipe[1]);
		free(line);
	}
	exit(EXIT_SUCCESS);
}

void	ft_get_heredoc(t_file **file, t_global *global)
{
	pid_t	child;
	int		herepipe[2];

	if (pipe(herepipe) < 0)
		ft_printerror(__func__, "Pipe");
	child = fork();
	if (child == 0)
	{
		global->in_heredoc = TRUE;
		ft_writetofile((*file)->name, herepipe, global);
	}
	else if (child < 0)
		ft_printerror(__func__, "Fork");
	else
		ft_wait_close_heredoc(child, *file, herepipe);
}
