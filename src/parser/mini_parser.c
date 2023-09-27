/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:37:00 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/27 18:27:29 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniparser.h"

t_bool	ft_is_wildcard(t_token token)
{
	if (token == tk_pipe || token == tk_and || token == tk_mul)
		return (TRUE);
	return (FALSE);
}

t_minitree	*ft_parse_tokens(char *line, t_token *token_array, int token_count)
{
	int			count;
	t_minitree	*minitree;

	count = 0;
	//IF command number > 1
	//Create tri_node
	while (count < token_count)
	{
		if (ft_is_wildcard(token_array[count]) == TRUE)
			ft_get_command(line, count);
		++count;
	}
	return (minitree);
}

t_minitree	*ft_parse_line(char *line, t_token *tokens_array, int token_count)
{
	t_list		*command_summary;

	if (!tokens_array || token_count <= 0)
		return (NULL);
	command_summary = ft_summarize(tokens_array, token_count);
	//PARSE Tokens
	ft_lstclear(&command_summary, free);
	return (NULL);
}
