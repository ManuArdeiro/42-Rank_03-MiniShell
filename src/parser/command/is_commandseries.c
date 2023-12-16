/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_commandseries.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:08:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/16 13:29:41 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	ft_verify_series(t_part *node, t_part *endnode)
{
	if (node != NULL)
	{
		while (node != endnode)
		{
			if (node->token == tk_cmd)
				return (TRUE);
			node = node->next;
		}
	}
	return (FALSE);
}

static t_bool	ft_is_validseries(t_part *node)
{
	t_bool	result;
	t_part	*endnode;

	endnode = NULL;
	result = FALSE;
	if (ft_is_tokenpair(node->token) == TRUE)
	{
		endnode
			= ft_get_tokennode(
				node->next->next,
				ft_get_tokenpair(node->next->token), FALSE, FIRST);
	}
	else if ((node->token == tk_cmd && node->next != NULL
			&& ft_is_tokenpair(node->next->token) == TRUE))
	{
		endnode
			= ft_get_tokennode(
				node->next,
				ft_get_tokenpair(node->token), FALSE, FIRST);
	}
	if (endnode != NULL)
		result = ft_verify_series(node, endnode);
	return (result);
}

t_bool	ft_is_commandseries(t_part *tokenlist)
{
	t_part	*node;
	t_bool	result;

	result = FALSE;
	if (tokenlist != NULL)
	{
		node = tokenlist;
		while (node != NULL)
		{
			result = ft_is_validseries(node);
			if (result == TRUE)
				break ;
			node = node->next;
		}
	}
	return (result);
}
