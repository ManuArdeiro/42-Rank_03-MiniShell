/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_seriestoken.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:29:13 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/15 20:13:46 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_part	*ft_get_last_seriestoken(t_part *tokenlist, t_part *delimiter)
{
	t_part	*node;

	if (tokenlist == NULL)
		return (NULL);
	node = tokenlist;
	while (node != delimiter
		&& node->next != NULL && node->next->token != tk_space)
		node = node->next;
	return (node);
}
