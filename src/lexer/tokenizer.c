/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:51:52 by jolopez-          #+#    #+#             */
/*   Updated: 2024/01/26 18:48:09 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function reads the tokens in the list passed as argument and
	distinguishes betweeen commands and arguments, assigning to each node the
	correct type.	*/

static t_bool	ft_is_tokenpin(t_part *node)
{
	if (node == NULL)
		return (FALSE);
	if (node->next != NULL && node->next->next != NULL)
	{
		if (node->next->token == tk_cmd
			&& node->next->next->token == tk_cmd)
			return (TRUE);
	}
	return (FALSE);
}

static void	ft_check_commandnode(
		t_part *node, t_token prev_token, int *flag, t_token token_pin)
{
	if (ft_is_tokenseparator(node->token) == TRUE)
		*flag = 0;
	else if (ft_is_redirection(node->token) == TRUE)
		*flag = 2;
	else if (prev_token == tk_arg && token_pin == tk_less)
		node->token = tk_cmd;
	else if (node->token == tk_cmd && *flag == 0)
		*flag = 1;
	else if (node->token == tk_cmd && *flag == 1)
		node->token = tk_arg;
	else if (*flag == 2
		&& (node->token == tk_cmd || node->token == tk_arg))
	{
		node->token = tk_file;
		*flag = 0;
	}
}

static void	ft_cmd_vs_arg(t_part *tokens)
{
	int		flag;
	t_part	*node;
	t_token	prev_token;
	t_token	token_pin;

	token_pin = 0;
	flag = 0;
	if (tokens == NULL)
		return ;
	node = tokens;
	while (node)
	{
		if (node->token == tk_less)
		{
			if (ft_is_tokenpin(node) == TRUE)
				token_pin = node->token;
		}
		ft_check_commandnode(node, prev_token, &flag, token_pin);
		prev_token = node->token;
		node = node->next;
	}
	if ((ft_last_tkn(tokens))->token == tk_space)
		ft_del_last_tkn(tokens);
	return ;
}

/*	This function converts a string passed as argument in a list of tokens,
	returns the pointer to the first node and save the number of tokens in
	a variable passed as argument. To do that:
	- ft_create_tkn_list creates a list of tokens.
	- ft_count_tokens counts the number of tokens.
	- ft_get_tokens recognize the tokens and creates a node for everyone of
	  them.
	- Finally ft_cmd_vs_arg recognize the arguments in the list of tokens.	*/

t_part	*ft_tokenizer(t_global *global, int *tk_count)
{
	t_part	*tokens;

	tokens = ft_create_tkn_list();
	if (!tokens)
		return (tokens);
	*tk_count = ft_count_tokens(global->line);
	ft_get_tokens(global->line, tokens);
	ft_cmd_vs_arg(tokens);
	return (tokens);
}
