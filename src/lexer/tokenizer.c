/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:51:52 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/05 11:43:45 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function reads the tokens in the list passed as argument and
	distinguishes betweeen commands and arguments, assigning to each node the
	correct type.	*/

static void	ft_cmd_vs_arg(t_part *tokens)
{
	int	flag;

	flag = 0;
	while (tokens)
	{
		if (tokens->token == tk_semi || tokens->token == tk_pipe)
			flag = 0;
		else if (tokens->token == tk_cmd && flag == 0)
			flag = 1;
		else if (tokens->token == tk_cmd && flag == 1)
			tokens->token = tk_arg;
		tokens = tokens->next;
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
