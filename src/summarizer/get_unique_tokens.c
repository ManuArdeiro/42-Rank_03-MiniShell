/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unique_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:36:48 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/03 16:51:07 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniparser.h"

static t_bool	ft_token_in_list(t_list *list, t_token token)
{
	t_list	*node;

	if (!list || token <= 0)
		return (FALSE);
	node = list;
	while (node != NULL)
	{
		if ((uintptr_t)(void *)node->content == token)
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}

t_list	*ft_get_unique_tokens(t_part *tokenlist)
{
	t_list	*list;
	t_part	*part;

	list = NULL;
	if (tokenlist == NULL)
		return (NULL);
	part = tokenlist;
	while (part != NULL)
	{
		if (ft_is_tokenpair(part->token) == TRUE)
			part = ft_skip_quotes(part->next, part->token);
		if (part != NULL)
		{
			if (ft_token_in_list(list, part->token) == FALSE)
			{
				if (part->token != 0)
					ft_lstinsert(&list, (void *)part->token, BACK);
			}
		}
		if (part != NULL)
			part = part->next;
	}
	return (list);
}
