/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_commandseries.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:29:13 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/07 20:24:16 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_series_substring(const char *commandline, t_part **node)
{
	t_part	*secondnode;
	char	*commandseries;

	commandseries = NULL;
	secondnode = ft_get_tokennode(
			(*node)->next, ft_get_tokenpair((*node)->token), FALSE, FIRST);
	if (secondnode != NULL && secondnode->end > (*node)->start)
		commandseries
			= ft_substr(
				commandline,
				(*node)->start + 1,
				(secondnode->end - 1) - ((*node)->start + 1));
	(*node) = secondnode;
	return (commandseries);
}

char	*ft_extract_commandseries(
	const char *commandline, t_part *tokenlist, t_global *global)
{
	t_part	*node;
	char	*commandseries;

	commandseries = NULL;
	if (commandline == NULL || tokenlist == NULL || global == NULL)
		return (NULL);
	node = tokenlist;
	while (node != NULL)
	{
		if (ft_is_tokenpair(node->token) == TRUE && node->next != NULL)
		{
			if (node->token == tk_dblquot)
				global->expand_dollartoken = TRUE;
			commandseries = ft_get_series_substring(commandline, &node);
		}
		node = node->next;
	}
	return (commandseries);
}
