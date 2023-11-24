/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executecommand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:44:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/18 14:30:27 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_expandlist(
	t_list **list, t_list *envlist, int laststatus)
{
	t_list	*node;
	char	*dollar_expansion;
	t_list	*prev_node;

	dollar_expansion = NULL;
	node = (*list);
	prev_node = NULL;
	while (node != NULL)
	{
		dollar_expansion
			= ft_expand_dollartoken(
				(char *)node->content, envlist, laststatus);
		if (dollar_expansion != NULL
			&& (char *)node->content != dollar_expansion)
		{
			free(node->content);
			node->content = dollar_expansion;
		}
		else if (dollar_expansion != NULL
			&& (char *)node->content == dollar_expansion)
		{
			if (ft_strrchr((char *)node->content, '\"') != NULL
				|| ft_strchr((char *)node->content, '\'') != NULL)
				ft_lst_nodejoin(prev_node, node);
		}
		prev_node = node;
		node = node->next;
	}
}

static void	ft_expand_wildcards(
		t_command *command, t_global *global, int laststatus)
{
	command->name
		= ft_expand_dollartoken(command->name, global->envlist, laststatus);
	ft_expandlist(&command->args, global->envlist, laststatus);
	ft_expandlist(&command->infile, global->envlist, laststatus);
	ft_expandlist(&command->outfile, global->envlist, laststatus);
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
