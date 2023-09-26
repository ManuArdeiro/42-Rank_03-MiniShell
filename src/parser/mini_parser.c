/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:37:00 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/26 20:41:48 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniparser.h"

t_command	*ft_parse_line(t_token *tokens_array, int token_count)
{
	t_list		*command_summary;

	if (!tokens_array || token_count <= 0)
		return (NULL);
	command_summary = ft_summarize(tokens_array, token_count);
	
	ft_lstclear(&command_summary, free);
	return (NULL);
}
