/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:28:55 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/04 20:29:09 by yzaytoun         ###   ########.fr       */
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
		const char *cleanline, const char *delimiter, int *herepipe
)
{
	if (ft_strequal(cleanline, delimiter) == TRUE)
	{
		ft_closepipe(&herepipe[0], &herepipe[1]);
		exit(EXIT_SUCCESS);
	}
	else if (g_signals.sig_exit_status == 1)
	{
		ft_closepipe(&herepipe[0], &herepipe[1]);
		exit(EXIT_FAILURE);
	}
}

void	ft_writetofile(const char *delimiter, int *herepipe)
{
	char	*line;
	char	*cleanline;

	line = "";
	cleanline = NULL;
	while (line != NULL)
	{
		ft_signals();
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		ft_get_inputline(&line, herepipe);
		cleanline = ft_strtrim(line, "\n");
		ft_evaluate_line(cleanline, delimiter, herepipe);
		ft_putstr_fd(line, herepipe[1]);
		free(line);
		free(cleanline);
	}
	exit(EXIT_SUCCESS);
}

void	ft_get_heredoc(t_file **file)
{
	pid_t	child;
	int		herepipe[2];

	if (pipe(herepipe) < 0)
		ft_printerror(__func__, "Pipe");
	child = fork();
	if (child == 0)
	{
		g_signals.in_heredoc = TRUE;
		ft_writetofile((*file)->name, herepipe);
	}
	else if (child < 0)
		ft_printerror(__func__, "Fork");
	else
		ft_wait_close_heredoc(child, *file, herepipe);
}
