/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:18:53 by jolopez-          #+#    #+#             */
/*   Updated: 2023/09/28 17:18:55 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_separator_token(t_csh *tcsh, t_oken **tokens, char *line, size_t *i)
{
	size_t				j;
	t_oken				*new;

	j = 0;
	(void)tcsh;
	while (g_separators[j] != NULL)
	{
		if (ft_strnequ(g_separators[j], &line[*i], ft_strlen(g_separators[j])))
		{
			new = create_token(tokens);
			if (new == NULL)
				return (1);
			*i += ft_strlen(g_separators[j]);
			new->str = ft_strdup(g_separators[j]);
		}
		j++;
	}
	return (0);
}