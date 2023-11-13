/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executecommand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:44:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/13 15:49:56 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_expand_wildcards(
		t_command *command, t_global *global, int laststatus)
{
	char	*dollar_expansion;
	t_list	*node;

	dollar_expansion = NULL;
	node = command->args;
	command->name
		= ft_expand_dollartoken(command->name, global->envlist, laststatus);
	while (node != NULL)
	{
		dollar_expansion
			= ft_expand_dollartoken(
				(char *)node->content, global->envlist, laststatus);
		if (dollar_expansion != NULL
			&& (char *)node->content != dollar_expansion)
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
	if (g_signals.sig_exit_status == 1)
		global->laststatus = g_signals.exit_status;
	laststatus = global->laststatus;
	g_signals.sig_exit_status = 0;
	ft_expand_wildcards(command, global, laststatus);
	ft_printcommand(command);
	pidcount = ft_create_subprocess(command, &pidarray, global);
	g_signals.pidarray = pidarray;
	g_signals.pidcount = pidcount;
	ft_signals();
	laststatus = ft_wait_subprocess(command, pidarray, pidcount);
	if (g_signals.sig_exit_status != 0)
		laststatus = g_signals.exit_status;
	global->laststatus = laststatus;
	if (pidarray != NULL)
		free(pidarray);
	g_signals.pidarray = NULL;
	return (laststatus);
}
