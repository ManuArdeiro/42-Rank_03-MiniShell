/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unique_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:36:48 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/29 19:05:28 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniparser.h"

static void	ft_add_token_to_list(t_list **list, t_token token)
{
	t_list	*new;

	if (token <= 0)
		return ;
	new = ft_lstnew((void *)(uintptr_t)token);
	ft_lstadd_front(list, new);
}

static t_bool	ft_token_in_list(t_list *list, t_token token)
{
	t_list	*node;

	if (!list || token <= 0)
		return (FALSE);
	node = list;
	while (node != NULL)
	{
		if ((t_token)node->content == token)
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
		if (ft_token_in_list(list, part->token) == FALSE)
			ft_add_token_to_list(&list, part->token);
		part = part->next;
	}
	return (list);
}
