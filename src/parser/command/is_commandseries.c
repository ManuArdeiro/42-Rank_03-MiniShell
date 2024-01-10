/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_commandseries.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:08:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/10 18:58:57 by yzaytoun         ###   ########.fr       */
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
	t_part	*sublist;
	t_token	tokenpair;

	result = TRUE;
	sublist = NULL;
	if (tokenlist != NULL)
	{
		if (tokenlist->token != tk_cmd
			&& ft_tokenlist_contains(tokenlist, ft_is_tokenpair) == TRUE
			&& ft_tokenlist_contains(tokenlist, ft_is_command) == TRUE)
		{
			tokenpair = ft_get_tokenpair(tokenlist->token);
			sublist
				= ft_copy_tokenlist(
					tokenlist,
					ft_get_tokennode(tokenlist->next, tokenpair, FALSE, FIRST));
			result = ft_check_series(sublist);
		}
		else
			result = FALSE;
	}
	return (result);
}
