/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tokenlist.c	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:50:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/17 19:14:36 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_set_tokenlist(t_part **tokenlist, t_part *delimiter, t_bool newstate)
{
	t_part	*node;

	if (tokenlist == NULL || *tokenlist == NULL)
		return ;
	node = *tokenlist;
	while (node != delimiter)
	{
		node->used = newstate;
		node = node->next;
	}
	if (delimiter != NULL)
		delimiter->used = TRUE;
}
