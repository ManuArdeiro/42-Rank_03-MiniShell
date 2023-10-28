/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tkn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:57:44 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/28 19:05:40 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function adds a new node to the list of t_part passed as 
	argument.	*/

static void	ft_default_set(
		t_part **new, t_token token, int start, int end)
{
	(*new)->token = token;
	(*new)->used = FALSE;
	(*new)->start = start;
	(*new)->end = end;
	(*new)->next = NULL;
}

int	ft_add_tkn(t_part *tokens, t_token token, int start, int end)
{
	t_part	*new;
	t_part	*last;

	new = malloc(sizeof(t_part) * 1);
	if (!new)
		return (EXIT_FAILURE);
	last = ft_last_tkn(tokens);
	if (tokens->index == 0)
	{
		tokens->index = 1;
		ft_default_set(&tokens, token, start, end);
		free(new);
	}
	else
	{
		new->index = ft_last_index(tokens) + 1;
		ft_default_set(&new, token, start, end);
		last->next = new;
	}
	return (EXIT_SUCCESS);
}
