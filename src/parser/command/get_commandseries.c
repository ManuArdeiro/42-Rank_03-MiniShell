/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commandseries.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:12:20 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/12 19:41:00 by jolopez-         ###   ########.fr       */
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
		t_part *node,
		t_part **subnode, t_cleancase *cleancase, t_global *global)
{
	(*subnode) = ft_get_last_seriestoken(node);
	(*cleancase) = ft_get_cleancase(node, (*subnode), global);
}

static void	ft_get_lastsubnode(
		t_part *node,
		t_part **subnode, t_cleancase *cleancase, t_global *global)
{
	(*subnode) = ft_get_last_seriestoken(node);
	(*cleancase) = ft_get_cleancase(node, (*subnode), global);
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
	ft_get_lastsubnode(*node, &sub_endnode, &cleancase, global);
	substring = ft_get_substr(commandline, sub_endnode, node);
	buffer = ft_strclean_withspaces(substring, cleancase);
	if (global->expand_dollartoken == TRUE)
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
	}
	return (commandseries);
}
