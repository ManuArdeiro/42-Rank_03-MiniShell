/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commandline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:40:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/26 21:01:10 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_navigate_and_execute(t_minitree *root, t_global *global)
{
	t_nodetype	*nodetype;

	if (root == NULL)
		return ;
	nodetype = ((t_mininode *)root->content)->type;
	if (nodetype == n_command)
		ft_executecommand(
			(t_command *)((t_mininode *)root->content)->content, global);
	else if (nodetype == n_and)
	{
		ft_navigate_and_execute(root->leftchild, global);
		ft_navigate_and_execute(root->rightchild, global);
	}
	else if (nodetype == n_or)
	{
		ft_navigate_and_execute(root->leftchild, global);
		if (global->laststatus == EXIT_FAILURE)
			ft_navigate_and_execute(root->rightchild, global);
	}
}

void	ft_execute_commandline(t_minitree *root, t_global *global)
{
	if (root == NULL || global == NULL)
		return ;
	ft_navigate_and_execute(root, global);
}
