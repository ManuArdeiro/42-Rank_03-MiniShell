/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:41:11 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/14 14:40:08 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_printnode(t_mininode *mininode)
{
	if (mininode == NULL)
		return ;
	if (mininode->content == NULL)
		printf("separator = ");
	else
		printf("nodetype = ");
	if (mininode->type == n_and_or)
		printf("n_and_or");
	else if (mininode->type == n_subshell)
		printf("n_subshell");
	else if (mininode->type == n_pipeline)
		printf("n_pipeline");
	else if (mininode->type == n_commandlist)
		printf("n_commandlist");
	else if (mininode->type == n_command)
		printf("n_command");
	printf("\n");
}

void	ft_printtree(t_minitree *root)
{
	if (root == NULL)
		return ;
	ft_printtree(root->leftchild);
	ft_printnode((t_mininode *)root->content);
	ft_printtree(root->rightchild);
}
