/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commandseries.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:12:20 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/11 21:07:49 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cleancase	ft_get_cleancase(t_part *startnode, t_part *endnode)
{
	if ((startnode->token == tk_sglquot || startnode->token == tk_arg)
		&& ft_contains_sub_tokenlist(startnode, endnode, tk_dblquot) == TRUE)
		return (CLEAN_SINGLE_QUOTES);
	else if ((startnode->token == tk_dblquot ||startnode->token == tk_arg)
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
				commandline, (*node)->start,
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

static void	ft_add_subseries(
	char **commandseries,
	t_part **node, const char *commandline, t_global *global)
{
	t_part		*sub_endnode;
	t_cleancase	cleancase;
	char		*buffer;
	char		*substring;

	buffer = NULL;
	substring = NULL;
	cleancase = CLEAN_ALL;
	sub_endnode = ft_get_tokennode((*node)->next, (*node)->token, FALSE, TRUE);
	if (sub_endnode != NULL
		&& sub_endnode->next != NULL && sub_endnode->next->token == tk_arg)
		sub_endnode = ft_get_last_seriestoken(sub_endnode);
	cleancase = ft_get_cleancase((*node), sub_endnode);
	substring = ft_get_substr(commandline, sub_endnode, node);
	buffer = ft_strclean_withspaces(substring, cleancase);
	if (global->expand_dollartoken == TRUE)
		buffer = ft_expand_dollartoken(buffer, global);
	(*commandseries) = ft_strjoin_get((*commandseries), buffer);
	if (substring != NULL)
		free(substring);
	if (buffer != NULL)
		free(buffer);
	if (sub_endnode != NULL && ft_is_tokenpair(sub_endnode->token) == FALSE)
		(*node) = sub_endnode->next;
	else
		(*node) = sub_endnode;
}

char	*ft_get_commandseries(
		const char *commandline,
		t_part *seriesstart, t_part *seriesend, t_global *global)
{
	t_part	*node;
	char	*commandseries;

	if (seriesstart == NULL || global == NULL)
		return (NULL);
	node = seriesstart;
	commandseries = NULL;
	while (node != NULL && node != seriesend)
	{
		if (ft_tokenlist_contains(node, ft_is_tokenpair) == TRUE)
		{
			if (node->token != tk_sglquot
				|| (node->next != NULL && node->next->token != tk_sglquot))
				global->expand_dollartoken = TRUE;
			ft_add_subseries(&commandseries, &node, commandline, global);
		}
		if (node != NULL && node != seriesend)
			node = node->next;
	}
	return (commandseries);
}
