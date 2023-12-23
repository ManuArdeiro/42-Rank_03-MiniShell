/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:28:55 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/23 16:07:08 by yzaytoun         ###   ########.fr       */
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
	if (ft_strequal(cleanline, delimiter) == TRUE)
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
	while (line != NULL)
	{
		ft_signals(global);
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

	if (global == NULL)
		return ;
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
