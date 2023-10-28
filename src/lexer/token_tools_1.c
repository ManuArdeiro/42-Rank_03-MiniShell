/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tools_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:15:42 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/28 18:56:35 by yzaytoun         ###   ########.fr       */
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
