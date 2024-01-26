/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:54:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/26 19:56:07 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	ft_isfile(t_token token)
{
	if (token == tk_file)
		return (TRUE);
	return (FALSE);
}

t_part	*ft_skip_redirection(t_part *tokenlist)
{
	t_part	*node;

	if (tokenlist == NULL)
		return (NULL);
	node = tokenlist;
	while (node != NULL)
	{
		if (ft_is_tokenpair(node->token) == TRUE
			|| ft_is_command(node->token) == TRUE
			|| ft_is_tokenseparator(node->token) == TRUE)
			break ;
		node = node->next;
	}
	if (node != NULL && ft_is_tokenpair(node->token) == TRUE
		&& ft_tokenlist_contains(node, ft_isfile) == TRUE)
	{
		node = ft_get_last_seriestoken(node);
		if (node != NULL)
			node = node->next;
	}
	return (node);
}
