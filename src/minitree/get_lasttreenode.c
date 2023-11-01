/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lasttreenode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:16:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/24 19:57:01 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minitree	*ft_get_lasttreenode(t_minitree *root, t_bool direction)
{
	if (root == NULL)
		return (NULL);
	if (direction == RIGHT)
	{
		if (ft_is_emptynode(root->rightchild) == TRUE)
			return (root);
		else
			ft_get_lasttreenode(root->rightchild, direction);
	}
	else if (direction == LEFT)
	{
		if (ft_is_emptynode(root->leftchild) == TRUE)
			return (root);
		else
			ft_get_lasttreenode(root->leftchild, direction);
	}
	return (NULL);
}
