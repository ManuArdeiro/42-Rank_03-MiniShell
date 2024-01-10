/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_commandseries.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:08:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/10 20:56:53 by jolopez-         ###   ########.fr       */
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

t_bool	ft_is_commandseries(t_part *tokenlist)
{
	t_bool	result;
	t_part	*endnode;
	t_part	*lastnode;

	result = TRUE;
	lastnode = NULL;
	if (tokenlist != NULL)
	{
		if (tokenlist->token != tk_cmd
			&& ft_tokenlist_contains(tokenlist, ft_is_tokenpair) == TRUE
			&& ft_tokenlist_contains(tokenlist, ft_is_command) == TRUE)
		{
			endnode = ft_get_tokennode(
					tokenlist->next,
					ft_get_tokenpair(tokenlist->token), FALSE, FIRST);
			lastnode = ft_get_lasttoken(tokenlist);
			if (endnode == lastnode
				|| (lastnode != NULL && lastnode->next != NULL
					&& endnode->index == lastnode->next->index))
				result = ft_check_series(tokenlist);
			else
				result = FALSE;
		}
		else
			result = FALSE;
	}
	return (result);
}
