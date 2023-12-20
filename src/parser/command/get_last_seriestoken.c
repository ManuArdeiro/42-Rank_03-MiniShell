/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_seriestoken.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:29:13 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/20 19:02:59 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_check_endnode(t_part *node, t_part **endnode)
{
	t_part	*pointer;

	pointer = NULL;
	pointer = ft_get_tokennode(node->next, node->token, TRUE, FIRST);
	if (pointer != NULL)
	{
		if ((pointer->next != NULL && pointer->next->token == tk_space)
			|| pointer->next == NULL)
		{
			(*endnode) = pointer;
		}
		else
		{
			(*endnode) = ft_get_tokennode(
					pointer->next, tk_space, TRUE, FIRST);
		}
	}
}

t_part	*ft_get_last_seriestoken(t_part *tokenlist)
{
	t_part	*node;
	t_part	*endnode;

	if (tokenlist == NULL)
		return (NULL);
	node = tokenlist;
	endnode = NULL;
	while (node->next != NULL)
	{
		if (ft_is_tokenpair(node->token) == TRUE)
		{
			ft_check_endnode(node, &endnode);
			break ;
		}
		node = node->next;
	}
	return (endnode);
}
