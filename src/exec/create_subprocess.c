/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_subprocess.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:50:44 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/26 20:47:37 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_fork_subprocess(
			t_command *command, pid_t **pid, int pidcount, t_global *global)
{
	t_list	*node;
	int		count;

	count = 0;
	if (command == NULL || *pid == NULL || global == NULL)
		return ;
	node = command->outfile;
	while (count < pidcount)
	{
		(*pid)[count] = fork();
		if ((*pid)[count] == 0)
		{
			ft_execute_subprocess(command,
				(t_file *)command->infile->content,
				(t_file *)node->content,
				global);
			node = node->next;
		}
		else if ((*pid)[count] < 0)
			ft_printerror(NULL, "Fork");
		++count;
	}
}

int	ft_create_subprocess(t_command *command, pid_t **pid, t_global *global)
{
	int		pidcount;

	pidcount = ft_lstsize(command->outfile);
	if (pidcount == 0)
		pidcount = 1;
	*pid = malloc(sizeof(pid_t) * pidcount);
	if (!*pid)
		return (0);
	ft_fork_subprocess(command, pid, pidcount, global);
	return (pidcount);
}
