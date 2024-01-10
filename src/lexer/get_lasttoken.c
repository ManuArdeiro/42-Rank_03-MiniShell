/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lasttoken.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:29:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/20 20:29:50 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_part	*ft_get_lasttoken(t_part *tokenlist)
{
	t_part	*last;
	t_part	*prev_node;

	if (tokenlist == NULL)
		return (NULL);
	last = tokenlist;
	prev_node = NULL;
	while (last->next != NULL)
	{
		prev_node = last;
		last = last->next;
	}
	if (last->token == tk_space)
		return (prev_node);
	return (last);
}
