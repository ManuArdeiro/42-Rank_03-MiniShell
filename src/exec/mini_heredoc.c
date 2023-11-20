/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:28:55 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/20 20:22:05 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_writetofile(const char *delimiter, int *herepipe)
{
	char	*line;
	int		delimiterlen;

	line = "";
	delimiterlen = ft_strlen(delimiter);
	while (line != NULL)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			ft_closepipe(&herepipe[0], &herepipe[1]);
			ft_printerror(__func__, "Get next line");
		}
		if (ft_strncmp(line, delimiter, delimiterlen) == 0)
		{
			ft_closepipe(&herepipe[0], &herepipe[1]);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, herepipe[1]);
		free(line);
	}
}

static void	ft_wait_and_close(pid_t child, t_file *file, int *herepipe)
{
	int		status;

	status = EXIT_SUCCESS;
	file->fd = dup(herepipe[0]);
	ft_closepipe(&herepipe[0], &herepipe[1]);
	if (waitpid(child, &status, EXIT_SUCCESS) < 0)
		ft_printerror(__func__, "Wait");
	ft_evaluate_subprocess(status);
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
		ft_wait_and_close(child, *file, herepipe);
}
