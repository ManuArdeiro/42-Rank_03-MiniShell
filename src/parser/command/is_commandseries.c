/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_commandseries.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:08:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/01 18:30:27 by yzaytoun         ###   ########.fr       */
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

t_bool	ft_is_commandseries(t_part *tokenlist)
{
	t_bool	result;
	t_part	*node;
	t_part	*endnode;

	result = FALSE;
	if (tokenlist != NULL)
	{
		node = tokenlist;
		while (node != NULL)
		{
			if (ft_is_tokenpair(node->token) == TRUE)
			{
				endnode
					= ft_get_tokennode(
						node->next,
						ft_get_tokenpair(node->token), FALSE, FIRST);
				if (endnode != NULL)
					result = ft_verify_series(node, endnode);
			}
			node = node->next;
		}
	}
	return (result);
}