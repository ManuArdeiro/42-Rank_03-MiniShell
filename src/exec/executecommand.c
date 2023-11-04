/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executecommand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:44:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/04 17:49:51 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_find_and_expand(
		t_command *command, t_global *global, int laststatus)
{
	char	*dollar_expansion;
	t_list	*node;

	dollar_expansion = NULL;
	node = command->args;
	while (node != NULL)
	{
		dollar_expansion
			= ft_expand_dollartoken(
				(char *)node->content, global->envlist, laststatus);
		if (dollar_expansion != NULL)
		{
			free(node->content);
			node->content = dollar_expansion;
		}
		node = node->next;
	}
}

int	ft_executecommand(t_command *command, t_global *global)
{
	pid_t	*pidarray;
	int		pidcount;
	int		laststatus;

	pidarray = NULL;
	if (command == NULL || global == NULL || command->name == NULL)
		return (EXITED);
	laststatus = global->laststatus;
	global->laststatus = EXIT_SUCCESS;
	ft_find_and_expand(command, global, laststatus);
	ft_printcommand(command);
	pidcount = ft_create_subprocess(command, &pidarray, global);
	laststatus = ft_wait_subprocess(command, pidarray, pidcount);
	if (pidarray != NULL)
		free(pidarray);
	global->laststatus = laststatus;
	return (laststatus);
}
