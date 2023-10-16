/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:41:11 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/16 19:24:49 by yzaytoun         ###   ########.fr       */
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
	if (mininode->type == n_and)
		printf("n_and");
	else if (mininode->type == n_or)
		printf("n_or");
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

static void	ft_printtree_recursive(t_minitree *root)
{
	if (root == NULL)
		return ;
	ft_printtree_recursive(root->leftchild);
	ft_printnode((t_mininode *)root->content);
	ft_printtree_recursive(root->rightchild);
}

void	ft_printtree(t_minitree *root)
{
	printf("********** ParseTree ************\n\n");
	ft_printtree_recursive(root);
	printf("--------------------------------\n");
}
