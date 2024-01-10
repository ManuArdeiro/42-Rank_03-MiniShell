/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_get_tokennode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:47:34 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/10 18:36:51 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	find_token(
		t_part **node, t_token token_tofind, t_bool strict)
{
	if (strict == TRUE)
	{
		if ((*node)->token == token_tofind && (*node)->used == FALSE)
		{
			(*node)->used = TRUE;
			return (TRUE);
		}
	}
	else
	{
		if ((*node)->token == token_tofind)
			return (TRUE);
	}
	return (FALSE);
}

t_part	*skip_get_tokennode(
		t_part *tokenlist, t_token token_tofind, t_bool strict)
{
	t_part	*node;

	if (tokenlist == NULL)
		return (NULL);
	node = tokenlist;
	while (node != NULL)
	{
		if (ft_is_subshellseparator(node->token) == TRUE)
			node = ft_skip_tokens(node->next, ft_is_subshellseparator);
		else if (ft_is_tokenpair(node->token) == TRUE)
			node = ft_skip_tokens(node->next, ft_is_tokenpair);
		if (node != NULL)
		{
			if (find_token(&node, token_tofind, strict) == TRUE)
				return (node);
			node = node->next;
		}
	}
	return (NULL);
}
