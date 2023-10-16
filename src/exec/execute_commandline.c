/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commandline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:40:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/16 19:50:23 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_evaluate_relation(t_minitree *root, char **envp)
{
	int			status;
	t_nodetype	nodetype;

	status = EXIT_SUCCESS;
	nodetype = ((t_mininode *)root->content)->type;
	if (nodetype == n_and)
	{
		ft_goto_childnode(root, envp, LEFT);
		ft_goto_childnode(root, envp, RIGHT);
	}
	else if (nodetype == n_or)
	{
		status = ft_goto_childnode(root, envp, LEFT);
		if (status == EXIT_FAILURE)
			status = ft_goto_childnode(root, envp, RIGHT);
	}
	else if (nodetype == n_pipeline)
		ft_execute_pipline((t_mininode *)root->content, envp);
	else if (nodetype == n_command)
		ft_executecommand(
			(t_command *)((t_mininode *)root->content)->content, envp);
}

static void	ft_navigate_and_execute(t_minitree *root, char **envp)
{
	if (root == NULL)
		return ;
	ft_evaluate_relation(root, envp);
	if (ft_is_emptynode(root->leftchild) == FALSE)
		ft_navigate_and_execute(root->leftchild, envp);
	if (ft_is_emptynode(root->rightchild) == FALSE)
		ft_navigate_and_execute(root->rightchild, envp);
}

void	ft_execute_commandline(t_minitree *root, t_list *envlist)
{
	char	**envp;

	if (root == NULL)
		return ;
	envp = ft_lstconvert_strarr(envlist);
	ft_navigate_and_execute(root, envp);
}
