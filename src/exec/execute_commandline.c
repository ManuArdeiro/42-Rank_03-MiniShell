/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commandline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:40:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/15 19:13:39 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_evaluate_relation(t_minitree *root, char **envp)
{
	int	status;

	status = EXIT_SUCCESS;
	if (ft_is_compoundcommand(((t_mininode *)root->content)->type) == TRUE)
	{
		if (status == EXIT_FAILURE)
			//execute next
		//evalute
	}
	else if (((t_mininode *)root->content)->type) == n_command)
		status = ft_executecommand(
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
