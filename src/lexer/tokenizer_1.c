/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:18:22 by jolopez-          #+#    #+#             */
/*   Updated: 2023/09/28 18:28:23 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


t_part	*ft_tokenizer_1(char *line, int *tk_count)
{
	t_part	*tokens;
	int		i;

	i = 0;
	tokens = ft_create_tkn_list();
	if (!tokens)
		return (EXIT_FAILURE);
	*tk_count = ft_count_tokens(line);
	tokens = malloc(sizeof(int) * *tk_count);
	if (!tokens)
		exit(EXIT_FAILURE);
	ft_get_tokens(line, tokens);
	ft_cmd_vs_arg(tokens, tk_count);
	return (tokens);
}
