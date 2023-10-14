/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokennode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:07:11 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/13 17:00:05 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_part	*ft_get_tokennode(t_part *tokenlist, t_token token, t_bool position)
{
	t_part	*node;

	if (tokenlist == NULL)
		return (NULL);
	node = tokenlist;
	while (node != NULL)
	{
		if (node->token == token && position == CURRENT_NODE
			&& node->used == FALSE)
		{
			node->used = TRUE;
			return (node);
		}
		else if (node->token == token && position == NEXT_NODE)
			return (node->next);
		node = node->next;
	}
	return (NULL);
}
