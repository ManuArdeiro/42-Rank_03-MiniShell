/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokennode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:07:11 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/08 19:44:09 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_part	*ft_search_tokenlist(t_part *tokenlist, t_bool strict, t_token token)
{
	t_part	*node;

	if (tokenlist == NULL)
		return (NULL);
	node = tokenlist;
	while (node != NULL)
	{
		if (strict == TRUE)
		{
			if (node->token == token && node->used == FALSE)
			{
				node->used = TRUE;
				return (node);
			}
		}
		else
		{
			if (node->token == token)
				return (node);
		}
		node = node->next;
	}
	return (NULL);
}

t_part	*ft_get_tokennode(
	t_part *tokenlist, t_token token, t_bool strict, t_bool direction)
{
	t_part	*listcopy;
	t_part	*node;

	listcopy = NULL;
	node = NULL;
	if (tokenlist == NULL)
		return (NULL);
	if (direction == LAST)
	{
		listcopy = ft_copy_tokenlist(tokenlist, NULL);
		ft_reverse_tokenlist(&listcopy);
		node
			= ft_get_token_byindex(
				tokenlist,
				ft_search_tokenlist(listcopy, strict, token));
	}
	else
		node = ft_search_tokenlist(tokenlist, strict, token);
	ft_free_tokenlist(&listcopy);
	return (node);
}
