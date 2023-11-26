/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commandline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:40:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/13 20:57:50 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_evaluate_relation(
		t_minitree *root,
		t_global *global, int *laststatus, t_nodetype nodetype)
{
	if (nodetype == n_and || nodetype == n_commandlist)
	{
		*laststatus = ft_navigate_and_execute(root->leftchild, global);
		*laststatus = ft_navigate_and_execute(root->rightchild, global);
	}
	else if (nodetype == n_or)
	{
		*laststatus = ft_navigate_and_execute(root->leftchild, global);
		if (*laststatus == EXIT_FAILURE || *laststatus == 127)
			*laststatus = ft_navigate_and_execute(root->rightchild, global);
	}
	else if (nodetype == n_pipeline)
		*laststatus = ft_execute_pipeline(root, global);
}

int	ft_navigate_and_execute(t_minitree *root, t_global *global)
{
	t_nodetype	nodetype;
	int			laststatus;

	laststatus = EXIT_SUCCESS;
	if (root == NULL || root->content == NULL)
		return (EXITED);
	nodetype = ((t_mininode *)root->content)->type;
	if (nodetype == n_command)
		laststatus
			= ft_executecommand(
				(t_command *)((t_mininode *)root->content)->content, global);
	else if (ft_is_compoundcommand(nodetype) == TRUE
		|| nodetype == n_pipeline)
		ft_evaluate_relation(root, global, &laststatus, nodetype);
	return (laststatus);
}

void	ft_execute_commandline(t_minitree *root, t_global *global)
{
	if (root == NULL || global == NULL)
		return ;
	ft_navigate_and_execute(root, global);
}
