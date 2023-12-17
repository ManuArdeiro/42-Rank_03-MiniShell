/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_commandseries.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:08:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/16 20:25:24 by yzaytoun         ###   ########.fr       */
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
			= ft_get_tokennode(tokenlist, tk_sglquot, TRUE, FIRST);
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

	result = TRUE;
	if (tokenlist != NULL)
	{
		if (ft_tokenlist_contains(tokenlist, ft_is_tokenpair) == TRUE
			&& ft_tokenlist_contains(tokenlist, ft_is_command) == TRUE)
			result = ft_check_series(tokenlist);
		else
			result = FALSE;
	}
	return (result);
}
