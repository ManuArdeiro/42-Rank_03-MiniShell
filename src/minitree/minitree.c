/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:57:40 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/27 18:34:16 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minitree	*ft_create_treenode(void *content)
{
	t_minitree	*newnode;

	newnode = malloc(sizeof(t_minitree));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->leftchild = NULL;
	newnode->rightchild = NULL;
	return (newnode);
}

t_minitree	*ft_insertleft(t_minitree *root, void *content)
{
	root->leftchild = ft_create_treenode(content);
	return (root->leftchild);
}

t_minitree	*ft_insertright(t_minitree *root, void *content)
{
	root->rightchild = ft_create_treenode(content);
	return (root->rightchild);
}

void	ft_destroytree(t_minitree *root)
{
	t_minitree	*node;

	if (root == NULL)
		return ;
	node = root;
	ft_destroytree(root->leftchild);
	ft_destroytree(root->rightchild);
	free(node);
}
