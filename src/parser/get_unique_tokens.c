/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unique_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:36:48 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/25 18:01:23 by yzaytoun         ###   ########.fr       */
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

t_list	*ft_get_unique_tokens(t_token *tokens_list, int token_count)
{
	t_list	*list;
	int		count;

	count = 0;
	list = NULL;
	while (count < token_count)
	{
		if (ft_token_in_list(list, tokens_list[count]) == FALSE)
			ft_add_token_to_list(&list, tokens_list[count]);
		++count;
	}
	return (list);
}
