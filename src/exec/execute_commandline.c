/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commandline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:40:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/10 17:01:19 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_execute_and(t_minitree *root, t_global *global, int *laststatus)
{
	int	firststatus;
	int	secondstatus;

	firststatus = EXIT_SUCCESS;
	secondstatus = EXIT_SUCCESS;
	firststatus = ft_navigate_and_execute(root->leftchild, global);
	if (firststatus == EXIT_SUCCESS)
	{
		secondstatus = ft_navigate_and_execute(root->rightchild, global);
		*laststatus = secondstatus;
	}
	else
		*laststatus = firststatus;
}

static void	ft_evaluate_relation(
		t_minitree *root,
		t_global *global, int *laststatus, t_nodetype nodetype)
{
	if (nodetype == n_and || nodetype == n_commandlist)
		ft_execute_and(root, global, laststatus);
	else if (nodetype == n_or)
	{
		*laststatus = ft_navigate_and_execute(root->leftchild, global);
		if (*laststatus != EXIT_SUCCESS)
			*laststatus = ft_navigate_and_execute(root->rightchild, global);
	}
	else if (nodetype == n_pipeline)
		*laststatus = ft_execute_pipeline(root, global);
	else if (nodetype == n_subshellcommand)
		*laststatus = ft_execute_subshell(root, global);
}

int	ft_navigate_and_execute(t_minitree *root, t_global *global)
{
	t_nodetype	nodetype;
	int			laststatus;

	laststatus = EXIT_FAILURE;
	if (root == NULL || root->content == NULL)
		return (EXITED);
	nodetype = ((t_mininode *)root->content)->type;
	if (nodetype == n_command)
	{
		laststatus
			= ft_executecommand(
				(t_command *)((t_mininode *)root->content)->content, global);
	}
	else if (ft_is_compoundcommand(nodetype) == TRUE
		|| nodetype == n_pipeline || nodetype == n_subshellcommand)
		ft_evaluate_relation(root, global, &laststatus, nodetype);
	return (laststatus);
}

void	ft_execute_commandline(t_minitree *root, t_global *global)
{
	if (root == NULL || global == NULL)
		return ;
	if (global->devmode == TRUE)
		ft_printtree(root);
	g_exit_status = ft_navigate_and_execute(root, global);
	global->laststatus = g_exit_status;
}
