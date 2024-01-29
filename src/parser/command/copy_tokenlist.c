/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_tokenlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:35:44 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/29 18:34:58 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_part	*ft_copy_tokenlist(t_part *tokenlist, t_part *delimiter)
{
	t_part		*node;
	t_part		*commandlist;
	t_part		*tokencopy;
	t_part		*endnode;

	commandlist = NULL;
	if (tokenlist == NULL)
		return (NULL);
	if (delimiter == NULL)
		endnode = delimiter;
	else
		endnode = delimiter->next;
	node = tokenlist;
	while (node != NULL
		&& (node != endnode
			|| (endnode != NULL && node->index != endnode->index)))
	{
		tokencopy = ft_copytoken(node);
		ft_tokenlist_add(&commandlist, tokencopy);
		node = node->next;
	}
	return (commandlist);
}
