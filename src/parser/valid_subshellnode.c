/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_subshellnode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:49:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/10 19:04:49 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_part	*ft_get_next_separatornode(t_part *tokenlist)
{
	t_part	*node;

	if (tokenlist == NULL)
		return (tokenlist);
	node = tokenlist;
	while (node != NULL)
	{
		if (ft_is_tokenpair(node->token) == TRUE)
			node = ft_skip_tokens(node->next, ft_is_tokenpair);
		if (node != NULL)
		{
			if (ft_is_tokenseparator(node->token) == TRUE)
				return (node);
			node = node->next;
		}
	}
	return (NULL);
}

t_bool	ft_valid_subshellnode(t_part *tokenlist)
{
	t_part	*subshell_node;
	t_part	*separatornode;

	subshell_node = NULL;
	separatornode = NULL;
	if (tokenlist == NULL)
		return (FALSE);
	if (is_complete_subshell(tokenlist) == FALSE)
		return (FALSE);
	separatornode = ft_get_next_separatornode(tokenlist);
	subshell_node = ft_get_tokennode(tokenlist, tk_lprnths, FALSE, FIRST);
	if ((subshell_node != NULL && separatornode == NULL)
		|| (subshell_node != NULL && separatornode != NULL
			&& subshell_node->index < separatornode->index))
		return (TRUE);
	return (FALSE);
}
