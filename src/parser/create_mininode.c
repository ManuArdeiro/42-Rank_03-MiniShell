/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mininode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:14:34 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/09 16:14:53 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mininode	*ft_create_mininode(void *content, t_nodetype type)
{
	t_mininode	*newnode;

	newnode = NULL;
	if (content)
	{
		newnode = malloc(sizeof(t_mininode));
		if (!newnode)
			return (NULL);
		newnode->content = content;
		newnode->type = type;
	}
	return (newnode);
}
