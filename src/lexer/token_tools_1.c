/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tools_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:15:42 by jolopez-          #+#    #+#             */
/*   Updated: 2023/09/29 19:23:02 by jolopez-         ###   ########.fr       */
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
	while (tokens)
	{
		if (tokens->next)
			return (tokens->index);
		tokens = tokens->next;
	}
	return (EXIT_FAILURE);
}

t_part	*ft_last_tkn(t_part *tokens)
{
	while (tokens)
	{
		if (!tokens->next)
			return (tokens);
		tokens = tokens->next;
	}
	return (tokens);
}

void	ft_add_tkn(t_part *tokens, int token, int start, int end)
{
	t_part	*new;
	t_part	*last;

	new = malloc(sizeof(t_part) * 1);
	if (!new)
		exit(EXIT_FAILURE);
	else
	{
		printf("tokens->index = %d \n", tokens->index);
		printf("ft_last_index(tokens) = %d \n", ft_last_index(tokens));
		if (ft_last_index(tokens) == 0)
			tokens = new;
		new->index = ft_last_index(tokens) + 1;
		printf("new->index = %d \n", new->index);
		new->token = token;
		new->start = start;
		new->end = end;
		new->next = NULL;
	}
	last = ft_last_tkn(tokens);
	last->next = new;
}
