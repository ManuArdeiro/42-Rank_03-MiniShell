/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commandline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:40:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/30 19:59:03 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_navigate_and_execute(t_minitree *root, t_global *global)
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
	else if (nodetype == n_and)
	{
		laststatus = ft_navigate_and_execute(root->leftchild, global);
		laststatus = ft_navigate_and_execute(root->rightchild, global);
	}
	else if (nodetype == n_or)
	{
		laststatus = ft_navigate_and_execute(root->leftchild, global);
		if (laststatus == EXIT_FAILURE)
			laststatus = ft_navigate_and_execute(root->rightchild, global);
	}
	else if (nodetype == n_pipeline)
		ft_add_pipeline(root);
	return (laststatus);
}

void	ft_execute_commandline(t_minitree *root, t_global *global)
{
	if (root == NULL || global == NULL)
		return ;
	ft_navigate_and_execute(root, global);
}
