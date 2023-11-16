/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_commandseries.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:29:13 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/16 20:57:20 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	ft_get_secondpair(t_token token)
{
	if (token == tk_lprnths)
		return (tk_rprnths);
	else if (token == tk_dblquot)
		return (tk_dblquot);
	else if (token == tk_sglquot)
		return (tk_sglquot);
	return (token);
}

char	*ft_extract_commandseries(const char *commandline, t_part *tokenlist)
{
	t_part	*node;
	t_part	*secondnode;
	char	*commandseries;

	commandseries = NULL;
	if (commandline == NULL || tokenlist == NULL)
		return (NULL);
	node = tokenlist;
	while (node != NULL)
	{
		if (ft_is_tokenpair(node->token) == TRUE)
		{
			secondnode = ft_get_tokennode(node, ft_get_secondpair(node->token));
			if (secondnode != NULL && secondnode->end > node->start)
				commandseries
					= ft_substr(
						commandline,
						node->start, secondnode->end - node->start + 1);
		}
		node = node->next;
	}
	return (commandseries);
}
