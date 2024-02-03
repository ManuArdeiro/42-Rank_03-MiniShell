/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:47:22 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/03 16:50:15 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_part	*ft_skip_quotes(t_part *tokenlist, t_token token)
{
	t_part	*node;

	if (tokenlist == NULL)
		return (NULL);
	node = tokenlist;
	while (node != NULL && node->token != token)
		node = node->next;
	return (node);
}
