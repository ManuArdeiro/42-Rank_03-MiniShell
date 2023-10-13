/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisummary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:05:07 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/13 14:55:02 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_summarize(t_part *tokens_list)
{
	t_list	*token_summary;
	t_list	*unique_token_list;

	token_summary = NULL;
	unique_token_list = ft_get_unique_tokens(tokens_list);
	token_summary
		= ft_get_token_summary(tokens_list, unique_token_list);
	ft_lstclear_nodes(&unique_token_list);
	return (token_summary);
}

void	ft_printsummary(t_list *token_summary)
{
	t_list	*node;

	if (token_summary == NULL)
		return ;
	node = token_summary;
	printf("**** Summary ****\n\n");
	while (node != NULL)
	{
		ft_print_token(((t_summarizer *) node->content)->token);
		printf("%d\n", ((t_summarizer *) node->content)->count);
		node = node->next;
	}
	printf("--------------------\n");
}
