/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commandlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:35:44 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/16 12:54:39 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_part	*ft_get_commandlist(t_part *tokenlist, t_part *delimiter)
{
	t_part		*node;
	t_part		*commandlist;
	t_part		*tokencopy;

	commandlist = NULL;
	if (tokenlist == NULL)
		return (NULL);
	node = tokenlist;
	while (node != NULL && (node != delimiter
		|| (delimiter != NULL && node->index != delimiter->index)))
	{
		tokencopy = ft_copytoken(node);
		ft_tokenlist_add(&commandlist, tokencopy);
		node = node->next;
	}
	return (commandlist);
}
