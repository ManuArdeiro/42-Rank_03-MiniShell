/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:51:52 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/13 15:56:40 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_cmd_vs_arg(t_part *tokens)
{
	int		flag;
	t_part	*node;

	flag = 0;
	node = tokens;
	while (node)
	{
		if (node->token == tk_semi || node->token == tk_pipe
			|| node->token == tk_or || node->token == tk_ampersand
			|| node->token == tk_lprnths || node->token == tk_and)
			flag = 0;
		else if (node->token == tk_cmd && flag == 0)
			flag = 1;
		else if (node->token == tk_cmd && flag == 1)
			node->token = tk_arg;
		node = node->next;
	}
}

t_part	*ft_tokenizer(char *line, int *tk_count)
{
	t_part	*tokens;

	tokens = ft_create_tkn_list();
	if (!tokens)
		return (tokens);
	*tk_count = ft_count_tokens(line);
	ft_get_tokens(line, tokens);
	ft_cmd_vs_arg(tokens);
	return (tokens);
}
