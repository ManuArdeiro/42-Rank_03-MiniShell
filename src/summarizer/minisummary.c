/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisummary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:05:07 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/29 19:02:49 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_summarize(t_part *tokens_list)
{
	t_list	*command_summary;
	t_list	*unique_token_list;

	unique_token_list = ft_get_unique_tokens(tokens_list);
	command_summary
		= ft_get_token_summary(tokens_list, unique_token_list);
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
		node = node->next;
	}
}
