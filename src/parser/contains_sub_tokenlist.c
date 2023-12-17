/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains_sub_tokenlist.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:32:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/17 14:38:08 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_contains_sub_tokenlist(
		t_part *startnode, t_part *endnode, t_token token)
{
	t_bool	result;
	t_part	*node;

	result = FALSE;
	if (startnode != NULL && token > 0)
	{
		node = startnode;
		while (node != endnode)
		{
			if (node->token == token)
			{
				result = TRUE;
				break ;
			}
			node = node->next;
		}
	}
	return (result);
}
