/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commandline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:40:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/24 20:03:18 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_evaluate_relation(t_minitree *root, t_global *global)
{
	t_nodetype	nodetype;

	global->status = EXIT_SUCCESS;
	nodetype = ((t_mininode *)root->content)->type;
	if (nodetype == n_and)
	{
		ft_goto_childnode(root, LEFT, global);
		ft_goto_childnode(root, RIGHT, global);
	}
	else if (nodetype == n_or)
	{
		ft_goto_childnode(root, LEFT, global);
		if (global->status == EXIT_FAILURE)
			ft_goto_childnode(root, RIGHT, global);
	}
	else if (nodetype == n_pipeline)
		ft_add_pipeline(root);
	else if (nodetype == n_command)
		ft_executecommand(
			(t_command *)((t_mininode *)root->content)->content, global);
}

static void	ft_navigate_and_execute(t_minitree *root, t_global *global)
{
	if (root == NULL)
		return ;
	ft_evaluate_relation(root, global);
	if (ft_is_emptynode(root->leftchild) == FALSE)
		ft_navigate_and_execute(root->leftchild, global);
	if (ft_is_emptynode(root->rightchild) == FALSE)
		ft_navigate_and_execute(root->rightchild, global);
}

void	ft_execute_commandline(t_minitree *root, t_global *global)
{
	if (root == NULL)
		return ;
	ft_navigate_and_execute(root, global);
}
