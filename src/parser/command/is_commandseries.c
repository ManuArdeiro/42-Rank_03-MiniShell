/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_commandseries.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:08:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/10 21:13:25 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	ft_check_series(t_part *tokenlist)
{
	t_bool	result;
	t_part	*commandnode;
	t_part	*quotenode;

	result = TRUE;
	commandnode = ft_get_tokennode(tokenlist, tk_cmd, FALSE, FIRST);
	quotenode = ft_get_tokennode(tokenlist, tk_dblquot, FALSE, FIRST);
	if (quotenode == NULL)
		quotenode
			= ft_get_tokennode(tokenlist, tk_sglquot, FALSE, FIRST);
	if (commandnode != NULL && quotenode != NULL)
	{
		if (commandnode->index < quotenode->index
			&& commandnode->next != NULL
			&& commandnode->next->token == tk_space)
			result = FALSE;
	}
	return (result);
}

static t_bool	ft_evaluate_subseries(t_part *node)
{
	t_part	*endnode;
	t_part	*lastnode;

	lastnode = NULL;
	if (node == NULL)
		return (FALSE);
	endnode = ft_get_tokennode(node->next,
			ft_get_tokenpair(node->token), FALSE, FIRST);
	lastnode = ft_get_lasttoken(node);
	if (endnode == lastnode
		|| (lastnode != NULL && lastnode->next != NULL
			&& endnode->index == lastnode->next->index))
		return (TRUE);
	return (FALSE);
}

t_bool	ft_is_commandseries(t_part *tokenlist)
{
	t_bool	result;

	result = TRUE;
	if (tokenlist != NULL)
	{
		if (tokenlist->token != tk_cmd
			&& ft_tokenlist_contains(tokenlist, ft_is_tokenpair) == TRUE
			&& ft_tokenlist_contains(tokenlist, ft_is_command) == TRUE)
		{
			if (ft_evaluate_subseries(tokenlist) == TRUE)
				result = ft_check_series(tokenlist);
			else
				result = FALSE;
		}
		else
			result = FALSE;
	}
	return (result);
}
