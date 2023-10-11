/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:41:11 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/11 12:47:43 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_printnode(t_mininode *mininode)
{
	if (mininode->type == n_and_or)
		printf("n_and_or\n");
	else if (mininode->type == n_subshell)
		printf("n_subshell\n");
	else if (mininode->type == n_pipeline)
		printf("n_pipeline\n");
	else if (mininode->type == n_newline_list)
		printf("n_newline_list\n");
	else if (mininode->type == n_command)
		printf("n_command\n");
}

void	ft_printtree(t_minitree *root)
{
	if (root == NULL)
		return ;
	ft_printtree(root->leftchild);
	printnode((t_mininode *)root->content);
	ft_printtree(root->rightchild);
}
