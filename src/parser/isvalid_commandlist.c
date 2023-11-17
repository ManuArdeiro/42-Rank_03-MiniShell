/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid_commandlist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:22:27 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/16 19:44:47 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	ft_is_validtokenpair(t_list *summary, t_summarizer *nodesummary)
{
	t_list			*node;
	t_token			tokenpair;
	t_summarizer	*secondsummary;

	secondsummary = NULL;
	if (summary == NULL)
		return (TRUE);
	node = summary;
	if (ft_is_tokenpair(nodesummary->token) == TRUE)
	{
		tokenpair = ft_get_tokenpair(nodesummary->token);
		while (node != NULL)
		{
			secondsummary = ((t_summarizer *)node->content);
			if (secondsummary != NULL && secondsummary->token == tokenpair)
			{
				if (secondsummary->count != nodesummary->count)
					return (FALSE);
			}
			node = node->next;
		}
	}
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
		if (nodesummary != NULL)
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
	if (ft_validate_summary(summary) == TRUE)
		result = TRUE;
	ft_lstclear_nodes(&summary);
	return (result);
}
