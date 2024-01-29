/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commandseries.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:12:20 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/29 18:39:43 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cleancase	ft_get_cleancase(
		t_part *startnode, t_part *endnode, t_global *global)
{
	if ((startnode->token == tk_sglquot || startnode->token == tk_arg)
		&& ft_contains_sub_tokenlist(startnode, endnode, tk_dblquot) == TRUE)
		return (CLEAN_SINGLE_QUOTES);
	else if ((startnode->token == tk_dblquot || startnode->token == tk_arg)
		&& ft_contains_sub_tokenlist(startnode, endnode, tk_sglquot) == TRUE)
	{
		global->expand_dollartoken = TRUE;
		return (CLEAN_DOUBLE_QUOTES);
	}
	else if (startnode->token == tk_dblquot)
		global->expand_dollartoken = TRUE;
	return (CLEAN_QUOTES);
}

static char	*ft_get_substr(
	const char *commandline, t_part *secondnode, t_part **node
)
{
	char	*buffer;

	buffer = NULL;
	if (secondnode != NULL && secondnode->end >= (*node)->start)
	{
		buffer = ft_substr(commandline, (*node)->start,
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

static void	ft_get_lastsubnode(
		t_part **node,
		t_part **subnode, t_cleancase *cleancase, t_global *global)
{
	if (ft_is_tokenpair((*node)->token) == TRUE)
	{
		(*subnode) = ft_get_tokennode(
				(*node)->next, (*node)->token, FALSE, FIRST);
		if ((*node)->token != tk_sglquot)
		{
			global->expand_dollartoken = TRUE;
			global->expand_startoken = TRUE;
		}
	}
	else if ((*node)->token == tk_dollar && (*node)->next != NULL
		&& ft_is_tokenpair((*node)->next->token) == TRUE)
	{
		(*subnode) = ft_get_tokennode(
				(*node)->next->next, (*node)->next->token, FALSE, FIRST);
		(*node) = (*node)->next;
	}
	else
	{
		(*subnode) = (*node);
		global->expand_dollartoken = TRUE;
	}
	(*cleancase) = ft_get_cleancase((*node), (*subnode), global);
}

static void	ft_add_subseries(char **commandseries,
		t_part **node, const char *commandline, t_global *global)
{
	t_part		*sub_endnode;
	t_cleancase	cleancase;
	char		*buffer;
	char		*substring;

	substring = NULL;
	cleancase = CLEAN_ALL;
	buffer = NULL;
	ft_get_lastsubnode(node, &sub_endnode, &cleancase, global);
	if (ft_is_emptyquotes(*node, sub_endnode) == TRUE
		&& sub_endnode != NULL && sub_endnode->next != NULL)
	{
		(*node) = sub_endnode;
		return ;
	}
	substring = ft_get_substr(commandline, sub_endnode, node);
	buffer = ft_strclean_withspaces(substring, cleancase);
	if (global->expand_dollartoken == TRUE && global->fileflag == FALSE)
		buffer = ft_expand_dollartoken(buffer, global);
	(*commandseries) = ft_strjoin_get((*commandseries), buffer);
	if (substring != NULL)
		free(substring);
	if (buffer != NULL)
		free(buffer);
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
		ft_add_subseries(&commandseries, &node, commandline, global);
		if (node != NULL && node != seriesend)
			node = node->next;
		global->expand_dollartoken = FALSE;
		global->expand_startoken = FALSE;
	}
	return (commandseries);
}
