/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lasttreenode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:16:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/21 20:38:53 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minitree	*ft_get_lasttreenode(t_minitree *root, t_bool direction)
{
	t_minitree	*node;

	if (root == NULL)
		return (NULL);
	if (direction == RIGHT)
	{
		if (ft_is_emptynode(root->rightchild) == TRUE)
			node = root;
		else if (((t_mininode *)root->content)->type == n_or)
			ft_get_lasttreenode(root->leftchild, direction);
		else
			ft_get_lasttreenode(root->rightchild, direction);
	}
	else if (direction == LEFT)
	{
		if (ft_is_emptynode(root->leftchild) == TRUE)
			node = root;
		else
			ft_get_lasttreenode(root->leftchild, direction);
	}
	return (node);
}