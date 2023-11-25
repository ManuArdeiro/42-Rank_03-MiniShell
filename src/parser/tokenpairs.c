/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenpairs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:45:12 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/25 17:37:13 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_is_tokenpair(t_token token)
{
	if (token == tk_dblquot || token == tk_sglquot)
		return (TRUE);
	return (FALSE);
}

t_bool	ft_contains_tokenpair(t_part *tokenlist)
{
	t_part	*node;

	if (tokenlist == NULL)
		return (FALSE);
	node = tokenlist;
	while (node != NULL)
	{
		if (ft_is_tokenpair(node->token) == TRUE)
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}
