/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_summary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:05:07 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/23 20:31:09 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniparser.h"

t_list	*ft_summarize(t_token *tokens_list, int token_count)
{
	t_list	*command_summary;
	t_list	*unique_token_list;

	unique_token_list = ft_get_unique_tokens(tokens_list, token_count);
	command_summary
		= ft_get_token_summary(tokens_list, token_count, unique_token_list);
	ft_lstclear_nodes(&unique_token_list);
	return (command_summary);
}

void	ft_printsummary(t_list *command_summary)
{
	t_list	*node;

	if (command_summary == NULL)
		return ;
	node = command_summary;
	while (node != NULL)
	{
		ft_print_token(((t_summarizer *) node->content)->token);
		printf("%d\n", ((t_summarizer *) node->content)->count);
		return ;
		node = node->next;
	}
}
