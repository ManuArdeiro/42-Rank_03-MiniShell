/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 20:07:38 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/29 20:08:00 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_part	*ft_get_tokennode(t_part *part, t_token token)
{
	t_part	*node;

	node = part;
	while (node != NULL)
	{
		if (node->token = token)
			return (node);
		node = node->next;
	}
}
