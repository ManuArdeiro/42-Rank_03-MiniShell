/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_commandseries.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:29:13 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/17 16:35:45 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_commandseries(const char *buffer, t_cleancase cleancase)
{
	//char	*commandseries;
	char	*finalcommandseries;

	finalcommandseries = NULL;
	finalcommandseries = ft_strclean_withspaces(buffer, cleancase);
	//if (cleancase == CLEAN_DOUBLE_QUOTES
	//	&& ft_strcontains(commandseries, "\'\'") == TRUE)
	//	finalcommandseries
	//		= ft_strclean_withspaces(commandseries, CLEAN_EMPTY_QUOTES);
	//else
	//	finalcommandseries = ft_strdup(commandseries);
	//free(commandseries);
	return (finalcommandseries);
}

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
	const char *commandline,
	t_part *secondnode, t_part **node, t_cleancase cleancase
)
{
	char	*commandseries;
	char	*buffer;

	commandseries = NULL;
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
	commandseries = ft_get_commandseries(buffer, cleancase);
	return (commandseries);
}

static char	*ft_get_series_substring(const char *commandline, t_part **node)
{
	t_part		*secondnode;
	char		*commandseries;
	t_cleancase	cleancase;

	commandseries = NULL;
	secondnode = NULL;
	secondnode = ft_get_last_seriestoken((*node));
	cleancase = ft_get_cleancase((*node), secondnode);
	commandseries = ft_get_substr(commandline, secondnode, node, cleancase);
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
