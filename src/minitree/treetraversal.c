/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treetraversal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:21:33 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/25 19:51:44 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitree.h"

void	ft_inorder_traversal(t_minitree *root, void (*function)(void *))
{
	if (root == NULL)
		return ;
	ft_inorder_traversal(root->leftchild, function);
	(*function)(root->content);
	ft_inorder_traversal(root->rightchild, function);
}

void	ft_preorder_traversal(t_minitree *root, void (*function)(void *))
{
	if (root == NULL)
		return ;
	(*function)(root->content);
	ft_preorder_traversal(root->leftchild, function);
	ft_preorder_traversal(root->rightchild, function);
}

void	ft_postorder_traversal(t_minitree *root, void (*function)(void *))
{
	if (root == NULL)
		return ;
	ft_postorder_traversal(root->leftchild, function);
	ft_postorder_traversal(root->rightchild, function);
	(*function)(root->content);
}
