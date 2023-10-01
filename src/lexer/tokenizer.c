/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:51:52 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/01 15:36:15 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
