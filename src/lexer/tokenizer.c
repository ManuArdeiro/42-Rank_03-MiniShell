/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:51:52 by jolopez-          #+#    #+#             */
/*   Updated: 2023/09/28 19:20:20 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_cmd_vs_arg(t_token *tokens, int *tk_count)
{
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	while (i < *tk_count)
	{
		if (tokens[i] == tk_semi || tokens[i] == tk_pipe
			|| tokens[i] == tk_ampersand)
			flag = 0;
		else if (tokens[i] == tk_cmd && flag == 0)
			flag = 1;
		else if (tokens[i] == tk_cmd && flag == 1)
			tokens[i] = tk_arg;
		i++;
	}
}

t_part	*ft_tokenizer(char *line, int *tk_count)
{
	t_part	*tokens;

	tokens = ft_create_tkn_list();
	if (!tokens)
		return (EXIT_FAILURE);
	//*tk_count = ft_count_tokens(line);
	ft_get_tokens(line, tokens);
	ft_cmd_vs_arg(tokens, tk_count);
	return (tokens);
}
