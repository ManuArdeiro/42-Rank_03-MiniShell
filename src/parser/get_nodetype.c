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

static t_bool	ft_evaluate_token(t_list *token_summary, (*validate)(token))
{
	t_bool	result;

	result = FALSE;
	if (list == NULL || (*validate) == NULL)
		return (FALSE);
	result = (*validate)(((t_summarizer *)token_summary->content)->token);
	return (result);
}

static t_nodetype	ft_get_listtype(t_list *token_summary)
{
	t_list	*node;

	if (token_summary == NULL)
		return (0);
	node = token_summary;
	while (node != NULL)
	{
		if (ft_evaluate_token(node, ft_is_logicalseparator) == TRUE)
			return (n_and_or);
		if (ft_evaluate_token(node, ft_is_subshellseparator) == TRUE)
			return (n_subshell);
		if (ft_evaluate_token(node, ft_is_pipeseparator) == TRUE)
			return (n_pipeline);
		if (ft_evaluate_token(node, ft_is_newline) == TRUE)
			return (n_pipeline);
		node = node->next;
	}
	return (0);
}

t_nodetype	ft_get_nodetype(t_part *tokenlist)
{
	t_part		*node;
	t_list		*token_summary;
	t_nodetype	nodetype;

	token_summary = ft_summarize(tokenlist);
	nodetype = ft_get_listtype(token_summary);
	if (!nodetype)
		ft_printerror(NULL, "No nodetype was found");
	ft_lstclear(token_summary, free);
	return (nodetype);
}
