/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_startnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:21:19 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/22 19:33:30 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_part	*ft_get_startnode(t_part *tokenlist)
{
	t_part	*startnode;

	if (tokenlist == NULL)
		return (NULL);
	startnode = tokenlist;
	while (startnode != NULL && startnode->used == TRUE)
		startnode = startnode->next;
	return (startnode);
}
