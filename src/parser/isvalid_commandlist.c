/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid_commandlist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:22:27 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/18 13:02:26 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	ft_validate_tokenlist(t_part *tokenlist)
{
	if (ft_is_tokenseparator(tokenlist->token) == TRUE
		&& tokenlist->index == 1)
		return (FALSE);
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
		if (nodesummary != NULL && ft_is_tokenpair(nodesummary->token) == TRUE)
		{
			if (ft_is_validtokenpair(node, nodesummary) == FALSE)
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
	ft_lstclear_nodes(&summary);
	return (result);
}
