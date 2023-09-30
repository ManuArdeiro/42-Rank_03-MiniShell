/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tools_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:15:42 by jolopez-          #+#    #+#             */
/*   Updated: 2023/09/30 19:05:50 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_space(char *line, int i)
{
	return (line[i] == ' ' || line[i] == '\t' || line[i] == '\v');
}

t_part	*ft_create_tkn_list(void)
{
	t_part	*part;

	part = malloc(sizeof(t_part));
	if (part)
	{
		part->index = 0;
		part->used = FALSE;
		part->token = 0;
		part->start = 0;
		part->end = 0;
		part->next = NULL;
		return (part);
	}
	return (NULL);
}

int	ft_last_index(t_part *tokens)
{
	t_part	*last;

	last = tokens;
	while (last)
	{
		if (!last->next)
			return (last->index);
		last = last->next;
	}
	return (EXIT_FAILURE);
}

t_part	*ft_last_tkn(t_part *tokens)
{
	t_part	*last;

	while (tokens)
	{
		if (!tokens->next)
			return (last);
		last = tokens->next;
	}
	return (last);
}

void	ft_add_tkn(t_part *tokens, t_token token, int start, int end)
{
	t_part	*new;
	t_part	*last;

	new = malloc(sizeof(t_part) * 1);
	if (!new)
		exit(EXIT_FAILURE);
	printf("reserva new hecha\n");
	last = ft_last_tkn(tokens);
	printf("ft_last_index(tokens) = %d\n", ft_last_index(tokens));
	last->next = new;
	if (ft_last_index(tokens) == 0)
	{
		tokens = new;
		tokens->index = 1;
	}
	else
		new->index = ft_last_index(tokens) + 1;
	new->token = token;
	new->used = FALSE;
	new->start = start;
	new->end = end;
	new->next = NULL;
}
