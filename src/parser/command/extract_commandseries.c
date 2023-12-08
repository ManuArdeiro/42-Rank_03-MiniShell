/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_commandseries.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:29:13 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/08 20:07:16 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_part	*ft_get_last_seriestoken(t_part *tokenlist)
{
	t_part	*node;

	if (tokenlist == NULL)
		return (NULL);
	node = tokenlist;
	while (node->next != NULL)
	{
		if (node->next->token == tk_space)
			return (node);
		node = node->next;
	}
	return (node);
}

static char	*ft_get_series_substring(const char *commandline, t_part **node)
{
	t_part	*secondnode;
	char	*commandseries;
	char	*buffer;

	commandseries = NULL;
	secondnode = ft_get_tokennode(
			(*node)->next, ft_get_tokenpair((*node)->token), FALSE, FIRST);
	if (secondnode != NULL
		&& secondnode->next != NULL && secondnode->next->token != tk_space)
		secondnode = ft_get_last_seriestoken(secondnode);
	if (secondnode != NULL && secondnode->end > (*node)->start)
	{
		buffer = ft_substr(commandline,
					(*node)->start + 1,
					((secondnode->end) - ((*node)->start) + 1));
		commandseries = ft_strclean_withspaces(buffer, TRUE);
	}
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
			if (node->token != tk_sglquot)
				global->expand_dollartoken = TRUE;
			commandseries = ft_get_series_substring(commandline, &node);
		}
		if (node != NULL)
			node = node->next;
	}
	return (commandseries);
}
