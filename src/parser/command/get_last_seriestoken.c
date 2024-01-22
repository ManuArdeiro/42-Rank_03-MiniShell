/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_seriestoken.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:07:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/22 19:19:37 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_mark_endnode(t_part *node, t_part **endnode)
{
	t_part	*pointer;

	pointer = NULL;
	if (ft_is_tokenpair(node->token) == FALSE && node->next != NULL)
	{
		pointer
			= ft_get_tokennode(
				node->next->next, node->next->token, FALSE, FIRST);
	}
	else
		pointer = ft_get_tokennode(node->next, node->token, FALSE, FIRST);
	if (pointer != NULL)
	{
		if ((pointer->next != NULL && pointer->next->token == tk_space)
			|| pointer->next == NULL)
			(*endnode) = pointer;
		else
			(*endnode) = ft_get_tokennode(
					pointer->next, tk_space, FALSE, FIRST);
	}
}

t_part	*ft_get_last_seriestoken(t_part *tokenlist)
{
	t_part	*endnode;

	if (tokenlist == NULL)
		return (NULL);
	endnode = NULL;
	ft_mark_endnode(tokenlist, &endnode);
	return (endnode);
}
