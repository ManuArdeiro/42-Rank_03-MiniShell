/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_seriestoken.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:07:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/26 19:16:59 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_part	*ft_get_nextseparator(t_part *tokenlist)
{
	t_part	*node;

	if (tokenlist == NULL)
		return (NULL);
	node = tokenlist;
	while (node->next != NULL)
	{
		if (ft_is_tokenseparator(node->next->token) == TRUE
			|| ft_is_redirection(node->next->token) == TRUE
			|| node->next->token == tk_space)
			return (node);
		node = node->next;
	}
	return (NULL);
}

static void	ft_mark_endnode(t_part *node, t_part **endnode)
{
	t_part	*pointer;

	pointer = NULL;
	if (ft_is_tokenpair(node->token) == TRUE && node->next != NULL)
		pointer = ft_get_tokennode(node->next, node->token, FALSE, FIRST);
	else
		pointer = ft_get_tokennode(node, node->token, FALSE, FIRST);
	if (pointer != NULL)
	{
		if ((pointer->next != NULL && pointer->next->token == tk_space)
			|| pointer->next == NULL)
			(*endnode) = pointer;
		else
			(*endnode) = ft_get_nextseparator(pointer);
	}
}

t_part	*ft_get_last_seriestoken(t_part *tokenlist)
{
	t_part	*endnode;

	if (tokenlist == NULL)
		return (NULL);
	endnode = NULL;
	ft_mark_endnode(tokenlist, &endnode);
	return (endnode);
}
