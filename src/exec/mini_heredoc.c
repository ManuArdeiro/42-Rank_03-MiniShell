/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:28:55 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/04 18:40:31 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_close_pipes(int *input, int *output)
{
	ft_closefile(input);
	ft_closefile(output);
}

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
			ft_closefile(&herepipe[0], &herepipe[1]);
			ft_printerror(__func__, "Get next line");
		}
		if (ft_strncmp(line, delimiter, delimiterlen) == 0)
		{
			ft_closefile(&herepipe[0], &herepipe[1]);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, herepipe[1]);
		free(line);
	}
}

//Save in the pipe
//Make file fd an array to save both files and pipes
void	ft_get_heredoc(t_file **file)
{
	pid_t	child;
	int		status;
	int		herepipe[2];

	status = 0;
	if (pipe(herepipe) < 0)
		ft_printerror(__func__, "Pipe");
	child = fork();
	if (child == 0)
		ft_writetofile(delimiter, herepipe);
	else if (child < 0)
		ft_printerror(__func__, "Fork");
	else
	{
		ft_duplicate_descriptors(&herepipe[0], /*Pipe goes here*/);
		ft_closefile(&herepipe[0], &herepipe[1]);
	}
	if (waitpid(child, &status, EXIT_SUCCESS) < 0)
		ft_printerror(__func__, "Wait");
	ft_evaluate_subprocess(status);
}
