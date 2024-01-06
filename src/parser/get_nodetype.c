/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nodetype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:23:19 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/05 20:42:03 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	ft_evaluate_token(
		t_list *token_summary, t_bool (*validate)(t_token))
{
	t_bool	result;

	result = FALSE;
	if (token_summary == NULL || (*validate) == NULL)
		return (FALSE);
	result = (*validate)(((t_summarizer *)token_summary->content)->token);
	return (result);
}

static t_nodetype	ft_find_listtype(t_list *token_summary)
{
	t_list	*node;

	if (token_summary == NULL)
		return (0);
	node = token_summary;
	while (node != NULL)
	{
		if (((t_summarizer *)node->content)->token == tk_and)
			return (n_and);
		else if (((t_summarizer *)node->content)->token == tk_or)
			return (n_or);
		else if (ft_evaluate_token(node, ft_is_subshellseparator) == TRUE)
			return (n_subshell);
		else if (ft_evaluate_token(node, ft_is_pipeseparator) == TRUE)
			return (n_pipeline);
		else if (ft_evaluate_token(node, ft_is_semicolon) == TRUE)
			return (n_commandlist);
		else if (((t_summarizer *)node->content)->token == tk_cmd
			&& ((t_summarizer *)node->content)->count == 1)
			return (n_commandlist);
		node = node->next;
	}
	return (n_empty);
}

t_nodetype	ft_get_nodetype(t_part *tokenlist)
{
	t_list		*token_summary;
	t_nodetype	nodetype;

	token_summary = NULL;
	token_summary = ft_summarize(tokenlist);
	nodetype = ft_find_listtype(token_summary);
	ft_lstclear(&token_summary, free);
	return (nodetype);
}
