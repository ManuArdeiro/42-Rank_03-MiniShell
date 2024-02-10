/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commandseries.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:12:20 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/10 15:09:27 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_check_tokencase(
		t_part **node, t_part **subnode, t_global *global)
{
	if ((*node)->token == tk_dollar && (*node)->next != NULL
		&& ft_is_tokenpair((*node)->next->token) == TRUE)
	{
		(*subnode) = ft_get_tokennode(
				(*node)->next->next, (*node)->next->token, FALSE, FIRST);
		(*node) = (*node)->next;
	}
	else if ((*node)->token == tk_dollar && (*node)->next != NULL
		&& (*node)->next->token != tk_space)
	{
		(*subnode) = (*node)->next;
		global->expand_dollartoken = TRUE;
	}
	else
	{
		(*subnode) = (*node);
		global->expand_dollartoken = TRUE;
	}
}

static t_cleancase	ft_get_cleancase(
		t_part *startnode, t_part *endnode, t_global *global)
{
	if ((startnode->token == tk_sglquot || startnode->token == tk_arg)
		&& ft_contains_sub_tokenlist(startnode, endnode, tk_dblquot) == TRUE)
	{
		return (CLEAN_SINGLE_QUOTES);
	}
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

static void	ft_get_lastsubnode(
		t_part **node,
		t_part **subnode, t_cleancase *cleancase, t_global *global)
{
	if (ft_is_tokenpair((*node)->token) == TRUE)
	{
		(*subnode) = ft_get_tokennode(
				(*node)->next, (*node)->token, FALSE, FIRST);
		if ((*node)->token != tk_sglquot)
			global->expand_dollartoken = TRUE;
		global->heredoc_quotes = TRUE;
	}
	else
		ft_check_tokencase(node, subnode, global);
	(*cleancase) = ft_get_cleancase((*node), (*subnode), global);
}

static void	ft_add_subseries(char **commandseries,
		t_part **node, t_global *global)
{
	t_part		*sub_endnode;
	t_cleancase	cleancase;
	char		*expandedstring;

	cleancase = CLEAN_ALL;
	ft_get_lastsubnode(node, &sub_endnode, &cleancase, global);
	if (ft_is_emptyquotes(*node, sub_endnode) == TRUE
		&& sub_endnode != NULL && sub_endnode->next != NULL)
	{
		(*node) = sub_endnode;
		return ;
	}
	expandedstring = ft_expandstring(global, (*node), sub_endnode, cleancase);
	(*commandseries) = ft_strjoin_get((*commandseries), expandedstring);
	if (ft_emptystring(expandedstring) == FALSE)
		free(expandedstring);
	(*node) = sub_endnode;
}

char	*ft_get_commandseries(
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
		ft_add_subseries(&commandseries, &node, global);
		if (node != NULL && node != seriesend)
			node = node->next;
		global->expand_dollartoken = FALSE;
	}
	return (commandseries);
}
