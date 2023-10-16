/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commandline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:40:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/15 17:59:02 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_checkexecute(t_mininode *mininode, char **envp)
{
	if (mininode == NULL)
		return ;
	if (mininode->type == n_command)
		ft_executecommand((t_command *)mininode->content, envp);
}
/*
static void	ft_navigate_and_execute(t_minitree *root, char **envp)
{
	if (root == NULL)
		return ;
	if (ft_is_emptynode(root->leftchild) == FALSE)
		ft_navigate_and_execute(root->leftchild, envp);
	ft_checkexecute(root, envp);
	if (ft_is_emptynode(root->rightchild) == FALSE)
		ft_navigate_and_execute(root->rightchild, envp);
}
*/

void	ft_execute_commandline(t_minitree *root, t_list *envlist)
{
	char	**envp;

	if (root == NULL)
		return ;
	envp = ft_lstconvert_strarr(envlist);
	ft_checkexecute((t_mininode *)root->content, envp);
	//ft_navigate_and_execute(root, envp);
}
