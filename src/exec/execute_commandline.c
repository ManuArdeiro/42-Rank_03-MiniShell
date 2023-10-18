/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commandline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:40:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/18 18:14:49 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_evaluate_relation(
		t_minitree *root, char **envp, t_global *global)
{
	int			status;
	t_nodetype	nodetype;

	status = EXIT_SUCCESS;
	nodetype = ((t_mininode *)root->content)->type;
	if (nodetype == n_and)
	{
		ft_goto_childnode(root, envp, LEFT, global);
		ft_goto_childnode(root, envp, RIGHT, global);
	}
	else if (nodetype == n_or)
	{
		status = ft_goto_childnode(root, envp, LEFT, global);
		if (status == EXIT_FAILURE)
			status = ft_goto_childnode(root, envp, RIGHT, global);
	}
	else if (nodetype == n_pipeline)
		ft_execute_pipline((t_mininode *)root->content, envp, global);
	else if (nodetype == n_command)
		ft_executecommand(
			(t_command *)((t_mininode *)root->content)->content, envp, global);
}

static void	ft_navigate_and_execute(
		t_minitree *root, char **envp, t_global *global)
{
	if (root == NULL)
		return ;
	ft_evaluate_relation(root, envp, global);
	if (ft_is_emptynode(root->leftchild) == FALSE)
		ft_navigate_and_execute(root->leftchild, envp, global);
	if (ft_is_emptynode(root->rightchild) == FALSE)
		ft_navigate_and_execute(root->rightchild, envp, global);
}

void	ft_execute_commandline(t_minitree *root, t_global *global)
{
	char	**envp;

	if (root == NULL)
		return ;
	envp = ft_lstconvert_strarr(global->envlist);
	ft_navigate_and_execute(root, envp, global);
}
