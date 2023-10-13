/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokennode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:07:11 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/13 16:29:46 by yzaytoun         ###   ########.fr       */
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
		if (node->token == token)
		{
			if (position == NEXT_NODE)
				return (node->next);
			else if (position == CURRENT_NODE)
				return (node);
		}
		node = node->next;
	}
	return (NULL);
}
