/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_commandseries.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:29:13 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/19 21:09:29 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cleancase	ft_get_cleancase(t_part *startnode, t_part *endnode)
{
	if (startnode->token == tk_sglquot
		&& ft_contains_sub_tokenlist(startnode, endnode, tk_dblquot) == TRUE)
		return (CLEAN_SINGLE_QUOTES);
	else if (startnode->token == tk_dblquot
		&& ft_contains_sub_tokenlist(startnode, endnode, tk_sglquot) == TRUE)
		return (CLEAN_DOUBLE_QUOTES);
	return (CLEAN_QUOTES);
}

static char	*ft_get_substr(
	const char *commandline, t_part *secondnode, t_part **node
)
{
	char	*buffer;

	buffer = NULL;
	if (secondnode != NULL && secondnode->end > (*node)->start)
	{
		buffer
			= ft_substr(
				commandline,
				(*node)->start,
				((secondnode->end) - ((*node)->start) + 1));
	}
	else if (secondnode == NULL)
	{
		secondnode = ft_get_lasttoken((*node));
		if (secondnode != NULL)
			buffer
				= ft_substr(commandline,
					(*node)->start,
					((secondnode->end) - ((*node)->start) + 1));
	}
	return (buffer);
}

static char	*ft_get_commandseries(
	const char *commandline, t_part *seriesstart, t_part *seriesend)
{
	t_part		*node;
	t_part		*sub_endnode;
	char		*buffer;
	char		*commandseries;
	t_cleancase	cleancase;

	node = seriesstart;
	buffer = NULL;
	cleancase = CLEAN_ALL;
	commandseries = NULL;
	while (node != NULL && node != seriesend)
	{
		if (ft_tokenlist_contains(node, ft_is_tokenpair) == TRUE)
		{
			sub_endnode = ft_get_tokennode(node->next, node->token, FALSE, TRUE);
			cleancase = ft_get_cleancase(node, sub_endnode);
			buffer = ft_strclean_withspaces(
					ft_get_substr(
							commandline, sub_endnode, &node), cleancase);
			commandseries = ft_strjoin_get(commandseries, buffer);
			node = sub_endnode;
		}
		if (node != NULL)
			node = node->next;
	}
	return (commandseries);
}


static char	*ft_get_series_substring(const char *commandline, t_part **node)
{
	t_part		*secondnode;
	char		*commandseries;

	commandseries = NULL;
	secondnode = NULL;
	secondnode = ft_get_last_seriestoken((*node));
	commandseries = ft_get_commandseries(commandline, (*node), secondnode);
	(*node) = secondnode;
	return (commandseries);
}

char	*ft_extract_commandseries(
	const char *commandline,
	t_part *tokenlist, t_part **nextstart, t_global *global)
{
	t_part	*node;
	char	*commandseries;

	commandseries = NULL;
	if (commandline == NULL || tokenlist == NULL || global == NULL)
		return (NULL);
	node = tokenlist;
	while (node != NULL && commandseries == NULL)
	{
		if ((ft_is_tokenpair(node->token) == TRUE
				&& node->used == FALSE && node->next != NULL)
			|| ((node->token == tk_cmd || node->token == tk_arg)
				&& node->next != NULL
				&&ft_is_tokenpair(node->next->token) == TRUE))
		{
			if (node->token != tk_sglquot)
				global->expand_dollartoken = TRUE;
			commandseries = ft_get_series_substring(commandline, &node);
		}
		if (node != NULL)
			node = node->next;
	}
	if (nextstart != NULL)
		(*nextstart) = node;
	return (commandseries);
}
