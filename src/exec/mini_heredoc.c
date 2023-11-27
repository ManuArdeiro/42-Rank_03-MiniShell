/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:28:55 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/27 20:10:01 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_writetofile(const char *delimiter, int *herepipe)
{
	char	*line;
	char	*cleanline;

	line = "";
	cleanline = NULL;
	while (line != NULL)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			ft_closepipe(&herepipe[0], &herepipe[1]);
			ft_printerror(__func__, "Get next line");
			exit(EXIT_FAILURE);
		}
		cleanline = ft_strtrim(line, "\n");
		if (ft_strequal(cleanline, delimiter) == TRUE)
		{
			ft_closepipe(&herepipe[0], &herepipe[1]);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, herepipe[1]);
		free(line);
		free(cleanline);
	}
}

void	ft_get_heredoc(t_file **file)
{
	pid_t	child;
	int		herepipe[2];

	if (pipe(herepipe) < 0)
		ft_printerror(__func__, "Pipe");
	child = fork();
	if (child == 0)
		ft_writetofile((*file)->name, herepipe);
	else if (child < 0)
		ft_printerror(__func__, "Fork");
	else
		ft_wait_close_heredoc(child, *file, herepipe);
}
