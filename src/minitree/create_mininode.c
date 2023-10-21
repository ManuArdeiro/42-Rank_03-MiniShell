/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mininode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:14:34 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/21 19:44:45 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mininode	*ft_create_mininode(void *content, t_nodetype nodetype)
{
	t_mininode	*newnode;

	newnode = NULL;
	if (nodetype != 0)
	{
		newnode = malloc(sizeof(t_mininode));
		if (!newnode)
			return (NULL);
		newnode->content = content;
		newnode->type = nodetype;
	}
	return (newnode);
}
