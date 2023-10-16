/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:51:52 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/14 20:48:01 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function reads the tokens in the list passed as argument and
	distinguishes betweeen commands and arguments, assigning to each node the
	correct type.	*/

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

/*	This function converts a string passed as argument in a lis of tokens,
	returns the pointer to the first node and save the number of tokens in
	a variable passed as argument. To do that:
	- ft_create_tkn_list creates a list of tokens.
	- ft_count_tokens counts the number of tokens.
	- ft_get_tokens recognize the tokens and creates a node for everyone of
	  them.
	- Finally ft_cmd_vs_arg recognize the arguments in the list of tokens.	*/

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
