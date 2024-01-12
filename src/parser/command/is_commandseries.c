/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_commandseries.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:08:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/12 20:27:07 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	ft_check_series(t_part *tokenlist)
{
	t_bool	result;
	t_part	*commandnode;
	t_part	*quotenode;

	result = FALSE;
	commandnode = ft_get_tokennode(tokenlist, tk_cmd, FALSE, FIRST);
	quotenode = ft_get_tokennode(tokenlist, tk_dblquot, FALSE, FIRST);
	if (quotenode == NULL)
		quotenode
			= ft_get_tokennode(tokenlist, tk_sglquot, FALSE, FIRST);
	if (quotenode != NULL)
		quotenode = ft_get_last_seriestoken(quotenode->next);
	if (commandnode != NULL && quotenode != NULL)
	{
		if (commandnode->index > quotenode->index
			|| commandnode->index == quotenode->index - 1
			|| commandnode->index == quotenode->index + 1)
			result = TRUE;
	}
	return (result);
}

t_bool	ft_is_commandseries(t_part *tokenlist)
{
	t_bool	result;

	result = FALSE;
	if (tokenlist != NULL)
		result = ft_check_series(tokenlist);
	return (result);
}
