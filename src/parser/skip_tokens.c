/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:26:41 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/08 20:02:15 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_part	*ft_skip_tokens(t_part *token, t_bool (*skipfunction)(t_token))
{
	t_part	*node;

	if (token == NULL || skipfunction == NULL)
		return (NULL);
	node = token;
	while (node != NULL && (*skipfunction)(node->token) == FALSE)
		node = node->next;
	return (node);
}
