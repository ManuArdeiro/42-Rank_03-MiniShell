/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains_tokenseparator.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:07:46 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/28 20:12:19 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_contains_tokenseparator(t_part *tokenlist)
{
	t_part	*node;

	if (tokenlist == NULL)
		return (FALSE);
	node = tokenlist;
	while (node != NULL)
	{
		if (ft_is_tokenseparator(node->token) == TRUE)
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}
