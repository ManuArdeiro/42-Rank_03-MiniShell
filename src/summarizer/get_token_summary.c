/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_summary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:16:23 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/31 19:10:19 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniparser.h"

static t_summarizer	*ft_count_token(t_part *tokenlist, t_token token)
{
	t_summarizer	*summarizer;
	t_part			*part;

	if (tokenlist == NULL || token <= 0)
		return (NULL);
	summarizer = ft_calloc(sizeof(t_summarizer), 1);
	if (!summarizer)
		return (NULL);
	part = tokenlist;
	while (part != NULL)
	{
		if (part->token == token)
			summarizer->count++;
		if (part != NULL)
			part = part->next;
	}
	summarizer->token = token;
	return (summarizer);
}

static void	ft_add_to_summary(t_list **summary, t_summarizer *summarizer)
{
	t_list	*new;

	if (summarizer != NULL)
	{
		new = ft_lstnew((t_summarizer *)summarizer);
		ft_lstadd_back(summary, new);
	}
}

t_list	*ft_get_token_summary(t_part *tokenlist, t_list *unique_token_list)
{
	t_list	*summary;
	t_list	*node;

	summary = NULL;
	if (!unique_token_list)
		return (NULL);
	node = unique_token_list;
	while (node != NULL)
	{
		ft_add_to_summary(
			&summary,
			ft_count_token(tokenlist, (uintptr_t)(void *)node->content)
			);
		node = node->next;
	}
	return (summary);
}
