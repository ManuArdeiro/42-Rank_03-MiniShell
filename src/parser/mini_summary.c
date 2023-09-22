/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_summary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:05:07 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/22 20:21:34 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniparser.h"

static t_list	*ft_get_unqiue_tokens(t_token *token_list)
{
	t_list	*list;

	
	return (list);
}

static t_summarizer	*ft_count_tokens(t_token *token_list)
{
	t_summarizer	*summarizer;
	t_list			*unique_tokens;

	if (!token_list)
		return (NULL);
	unique_tokens = ft_get_unqiue_tokens(token_list);
	return (summarizer);
}

t_list	*ft_summarize(t_token *tokens_list)
{
	t_list	*command_summary;

	// get unique commands 
	//count command
	//
	return (command_summary);
}