/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tools_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:15:42 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/01 03:33:09 by jolopez-         ###   ########.fr       */
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
	while (last->next != NULL)
		last = last->next;
	return (last->index);
}

t_part	*ft_last_tkn(t_part *tokens)
{
	t_part	*last;

	last = tokens;
	while (last->next != NULL)
		last = tokens->next;
	return (last);
}

void	ft_add_tkn(t_part *tokens, t_token token, int start, int end)
{
	t_part	*new;
	t_part	*last_tk;

	new = malloc(sizeof(t_part) * 1);
	if (!new)
		exit(EXIT_FAILURE);
	new->token = token;
	new->used = FALSE;
	new->start = start;
	new->end = end;
	new->next = NULL;
	last_tk = ft_last_tkn(tokens);
	last_tk->next = new;
	if (ft_last_index(tokens) == 0)
	{
		free(tokens);
		tokens = new;
		tokens->index = 1;
	}
	else
		new->index = ft_last_index(tokens) + 1;
}
