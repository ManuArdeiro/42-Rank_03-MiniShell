/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lasttreenode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:16:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/02 19:19:32 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minitree	*ft_get_lasttreenode(t_minitree *root, t_bool direction)
{
	t_minitree	*node;

	if (root == NULL)
		return (NULL);
	node = root;
	while (node != NULL)
	{
		if (direction == RIGHT)
		{
			if (ft_is_emptynode(node->rightchild) == TRUE)
				return (node);
			node = node->rightchild;
		}
		else if (direction == LEFT)
		{
			if (ft_is_emptynode(node->leftchild) == TRUE)
				return (node);
			node = node->leftchild;
		}
	}
	return (NULL);
}
