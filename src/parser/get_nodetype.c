/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nodetype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:23:19 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/10 15:58:33 by yzaytoun         ###   ########.fr       */
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

static t_nodetype	ft_define_listtype(t_list *token_summary)
{
	t_list	*node;

	if (token_summary == NULL)
		return (0);
	node = token_summary;
	while (node != NULL)
	{
		if (ft_evaluate_token(node, ft_is_logicalseparator) == TRUE)
			return (n_and_or);
		else if (ft_evaluate_token(node, ft_is_subshellseparator) == TRUE)
			return (n_subshell);
		else if (ft_evaluate_token(node, ft_is_pipeseparator) == TRUE)
			return (n_pipeline);
		node = node->next;
	}
	return (n_command);
}

t_nodetype	ft_get_nodetype(t_part *tokenlist)
{
	t_list		*token_summary;
	t_nodetype	nodetype;

	token_summary = NULL;
	token_summary = ft_summarize(tokenlist);
	nodetype = ft_define_listtype(token_summary);
	ft_lstclear_nodes(&token_summary);
	return (nodetype);
}
