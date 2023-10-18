/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tools_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:15:42 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/18 16:33:34 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function returs 1 if the character is space (or tabs), 0 if not.	*/

int	ft_is_space(char *line, int i)
{
	return (line[i] == ' ' || line[i] == '\t' || line[i] == '\v');
}

/*Revisar la salida de error*/

t_part	*ft_create_tkn_list(void)
{
	t_part	*part;

	part = malloc(sizeof(t_part));
	if (!part)
		return (NULL);
	else
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

/*	This function returns the index of the last t_part node of the
	list (of t_part) passed as argument.	*/

int	ft_last_index(t_part *tokens)
{
	t_part	*last_idx;

	last_idx = tokens;
	while (last_idx->next != NULL)
		last_idx = last_idx->next;
	return (last_idx->index);
}

/*	This function returns the last t_part node of the list (of t_part)
	passed as argument.	*/

t_part	*ft_last_tkn(t_part *tokens)
{
	t_part	*last_tk;

	last_tk = tokens;
	while (last_tk->next != NULL)
		last_tk = last_tk->next;
	return (last_tk);
}

/*	This function adds a new node to the list of t_part passed as 
	argument.	*/

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
		tokens->token = token;
		tokens->used = FALSE;
		tokens->start = start;
		tokens->end = end;
		tokens->next = NULL;
		free(new);
	}
	else
	{
		new->index = ft_last_index(tokens) + 1;
		new->token = token;
		new->used = FALSE;
		new->start = start;
		new->end = end;
		new->next = NULL;
		last->next = new;
	}
	return (EXIT_SUCCESS);
}
