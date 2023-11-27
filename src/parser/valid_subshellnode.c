/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_subshellnode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:49:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/27 19:23:02 by yzaytoun         ###   ########.fr       */
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
		if (ft_is_tokenseparator(node->token) == TRUE)
			return (node);
		node = node->next;
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
	separatornode = ft_get_next_separatornode(tokenlist);
	subshell_node = ft_get_tokennode(tokenlist, tk_lprnths, FALSE, FIRST);
	if ((subshell_node != NULL && separatornode == NULL)
		|| (subshell_node != NULL && separatornode != NULL
			&& subshell_node->index < separatornode->index))
		return (TRUE);
	return (FALSE);
}
