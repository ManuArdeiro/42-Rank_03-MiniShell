/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:26:41 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/05 20:22:56 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_part	*ft_skip_quotes(t_part *token)
{
	t_part	*node;

	if (token == NULL)
		return (NULL);
	node = token;
	while (node != NULL && ft_is_tokenpair(node->token) == FALSE)
		node = node->next;
	return (node);
}
