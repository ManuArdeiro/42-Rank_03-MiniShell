/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_summary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:16:23 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/23 20:17:35 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniparser.h"

static t_summarizer	*ft_get_token_count(
		t_token *token_list, t_token token, int token_count)
{
	t_summarizer	*summarizer;
	int				count;

	if (token <= 0)
		return (NULL);
	count = 0;
	summarizer = ft_calloc(sizeof(t_summarizer), 1);
	if (!summarizer)
		return (NULL);
	while (count < token_count)
	{
		if (token_list[count] == token)
			summarizer->count++;
		count++;
	}
	summarizer->token = token;
	return (summarizer);
}

static void	ft_add_to_summary(t_list **summary, t_summarizer *summarizer)
{
	t_list			*new;

	if (summarizer)
	{
		new = ft_lstnew((t_summarizer *)summarizer);
		ft_lstadd_back(summary, new);
	}
}

t_list	*ft_get_token_summary(
			t_token *token_list, int token_count, t_list *unique_token_list)
{
	t_list	*summary;
	t_list	*node;

	if (!unique_token_list)
		return (NULL);
	node = unique_token_list;
	summary = NULL;
	while (node != NULL)
	{
		ft_print_token(*((t_token *)(node)->content));
		printf("token = %d\n", *(t_token *)(node)->content);
		ft_add_to_summary(
			&summary,
			ft_get_token_count(
				token_list, *((t_token *)node->content), token_count)
			);
		node = node->next;
	}
	return (summary);
}
