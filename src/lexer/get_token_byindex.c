/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_byindex.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:07:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/25 17:14:36 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_part	*ft_get_token_byindex(t_part *tokenlist, t_part *token_tofind)
{
	t_part	*node;

	if (tokenlist == NULL || token_tofind == NULL)
		return (NULL);
	node = tokenlist;
	while (node != NULL)
	{
		if (node->index == token_tofind->index)
			return (node);
		node = node->next;
	}
	return (NULL);
}
