/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tokenlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:36:46 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/19 18:51:26 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	ft_evaluate_subshell(t_part *endnode)
{
	if (endnode->next != NULL)
	{
		if (endnode->next->token != tk_space
			&& ft_is_tokenseparator(endnode->next->token) == FALSE)
			return (FALSE);
		else if (endnode->next->token == tk_space
			&& endnode->next->next != NULL
			&& ft_is_tokenseparator(endnode->next->next->token) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

static t_bool	ft_validate_subshell(t_part *tokenlist)
{
	t_part	*node;
	t_part	*endnode;
	int		result;

	node = tokenlist;
	endnode = NULL;
	result = TRUE;
	while (node != NULL)
	{
		if (ft_is_subshellseparator(node->token))
		{
			endnode = ft_get_tokennode(node->next,
					ft_get_tokenpair(node->token), FALSE, FIRST);
			if (endnode != NULL)
				result = ft_evaluate_subshell(endnode);
			else
				result = FALSE;
			node = endnode;
		}
		if (node != NULL)
			node = node->next;
	}
	return (result);
}

t_bool	ft_validate_tokenlist(t_part *tokenlist)
{
	int		result;

	result = TRUE;
	if (tokenlist == NULL)
		return (FALSE);
	if (ft_is_tokenseparator(tokenlist->token) == TRUE
		&& tokenlist->index == 1)
		result = FALSE;
	result = ft_validate_subshell(tokenlist);
	return (result);
}
