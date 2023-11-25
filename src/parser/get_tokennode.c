/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokennode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:07:11 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/25 17:32:28 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_part	*ft_get_tokennode(t_part *tokenlist, t_token token, t_bool strict)
{
	t_part	*node;

	if (tokenlist == NULL)
		return (NULL);
	node = tokenlist;
	while (node != NULL)
	{
		if (strict == TRUE)
		{
			if (node->token == token && node->used == FALSE)
			{
				node->used = TRUE;
				return (node);
			}
		}
		else
		{
			if (node->token == token)
				return (node);
		}
		node = node->next;
	}
	return (NULL);
}
