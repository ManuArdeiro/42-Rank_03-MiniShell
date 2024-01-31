/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid_commandlist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:22:27 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/31 18:42:38 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	ft_valid_commandseries(t_part *tokenlist)
{
	t_part	*node;
	t_part	*endnode;

	if (tokenlist == NULL)
		return (FALSE);
	node = tokenlist;
	endnode = NULL;
	while (node != NULL)
	{
		if (ft_is_tokenpair(node->token) == TRUE)
		{
			endnode
				= ft_get_tokennode(
					node->next,
					ft_get_tokenpair(node->token), FALSE, FIRST);
			if (endnode == NULL)
				return (FALSE);
			else
				node = endnode;
		}
		node = node->next;
	}
	return (TRUE);
}

static t_bool	ft_is_validtokenpair(t_list *summary, t_summarizer *nodesummary)
{
	t_token	tokenpair;
	int		tokencount;

	if (summary == NULL || nodesummary == NULL)
		return (TRUE);
	tokenpair = ft_get_tokenpair(nodesummary->token);
	tokencount = ft_get_tokencount(summary, tokenpair);
	if (tokenpair == nodesummary->token)
	{
		if (nodesummary->count % 2 != 0)
			return (FALSE);
	}
	else if (tokencount == 0 || tokencount != nodesummary->count)
		return (FALSE);
	return (TRUE);
}

static t_bool	ft_validate_summary(t_list *summary)
{
	t_list			*node;
	t_summarizer	*nodesummary;

	nodesummary = NULL;
	if (summary == NULL)
		return (FALSE);
	node = summary;
	while (node != NULL)
	{
		nodesummary = (t_summarizer *)node->content;
		if (ft_is_tokenpair(nodesummary->token) == TRUE
			|| ft_is_subshellseparator(nodesummary->token) == TRUE)
		{
			if (ft_is_validtokenpair(summary, nodesummary) == FALSE)
				return (FALSE);
		}
		else if (ft_is_tokenseparator(nodesummary->token) == TRUE
			&& nodesummary->token != tk_semi)
		{
			if (nodesummary->count >= ft_get_tokencount(summary, tk_cmd))
				return (FALSE);
		}
		node = node->next;
	}
	return (TRUE);
}

t_bool	ft_isvalid_commandlist(t_part *tokenlist)
{
	t_list	*summary;
	t_bool	result;

	summary = NULL;
	result = FALSE;
	if (tokenlist == NULL)
		return (FALSE);
	summary = ft_summarize(tokenlist);
	if (ft_validate_tokenlist(tokenlist) == TRUE
		&& ft_validate_summary(summary) == TRUE)
		result = TRUE;
	if (result == TRUE
		&& ft_tokenlist_contains(tokenlist, ft_is_tokenpair) == TRUE)
	{
		result = FALSE;
		if (ft_valid_commandseries(tokenlist) == TRUE)
			result = TRUE;
	}
	ft_lstclear(&summary, ft_clearsummary);
	return (result);
}
