/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:57:40 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/28 19:43:14 by yzaytoun         ###   ########.fr       */
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

void	ft_destroytree(t_minitree **root, void (*free_function)(void *))
{
	t_minitree	*node;

	if (root == NULL || (*root) == NULL)
		return ;
	node = *root;
	ft_destroytree(&(*root)->leftchild, free_function);
	ft_destroytree(&(*root)->rightchild, free_function);
	free_function(node->content);
	free(node);
	*root = NULL;
}

void	ft_treeinsert(
	t_minitree **root, void *leftcontent, void *rootcontent, void *rightcontent)
{
	(*root) = ft_create_treenode(rootcontent);
	(*root)->leftchild = ft_insertleft(*root, leftcontent);
	(*root)->rightchild = ft_insertright(*root, rightcontent);
}
