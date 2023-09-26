/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:51:52 by jolopez-          #+#    #+#             */
/*   Updated: 2023/09/26 20:13:19 by jolopez-         ###   ########.fr       */
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

t_token	*ft_tokenizer(char *line, int *tk_count)
{
	int		i;
	int		j;
	t_token	*tokens;

	i = 0;
	j = 0;
	*tk_count = ft_count_tokens(line);
	tokens = malloc(sizeof(int) * *tk_count);
	if (!tokens)
		exit(1);
	ft_get_tokens(line, tokens, &i, &j);
	ft_cmd_vs_arg(tokens, tk_count);
	return (tokens);
}
