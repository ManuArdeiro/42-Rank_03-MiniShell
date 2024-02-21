/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenlist_contains.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:38:48 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/21 19:31:06 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_tokenlist_contains(
	t_part *tokenlist, t_bool (*function)(t_token token))
{
	t_part	*node;

	if (tokenlist == NULL || (*function) == NULL)
		return (FALSE);
	node = tokenlist;
	while (node != NULL)
	{
		if ((*function)(node->token) == TRUE)
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}

/*
	Skips quotes
*/
t_bool	ft_skip_tokenlist_contains(
	t_part *tokenlist, t_bool (*function)(t_token token))
{
	t_part	*node;

	if (tokenlist == NULL || (*function) == NULL)
		return (FALSE);
	node = tokenlist;
	while (node != NULL)
	{
		if (ft_is_tokenpair(node->token) == TRUE)
			node = ft_skip_quotes(node->next, node->token);
		if (node != NULL)
		{
			if ((*function)(node->token) == TRUE)
				return (TRUE);
			node = node->next;
		}
	}
	return (FALSE);
}
