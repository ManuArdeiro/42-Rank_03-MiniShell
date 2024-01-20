/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractseries.c	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:50:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/17 19:14:36 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	ft_isfile(t_token token)
{
	if (token == tk_file)
		return (TRUE);
	return (FALSE);
}

static t_part	*ft_skip_redirection(t_part *tokenlist)
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
	if (ft_is_tokenpair(node->token) == TRUE
		&& ft_tokenlist_contains(node, ft_isfile) == TRUE)
	{
		node = ft_get_last_seriestoken(node);
		if (node != NULL)
			node = node->next;
	}
	return (node);
}

static char	*ft_extract_quoteseries(t_part *node, t_global *global)
{
	char	*commandname;
	t_part	*finalnode;

	commandname = NULL;
	finalnode = ft_get_last_seriestoken(node);
	ft_set_tokenlist(&node, finalnode, TRUE);
	commandname = ft_get_commandseries(global->line, node, finalnode, global);
	return (commandname);
}

char	*ft_extractseries(t_part *tokenlist, t_global *global)
{
	char	*commandname;
	t_part	*node;

	if (tokenlist == NULL || global == NULL)
		return (NULL);
	commandname = NULL;
	node = tokenlist;
	if (node->used == FALSE
		&& ft_is_redirection(node->token) == TRUE && node->next != NULL)
		node = ft_skip_redirection(tokenlist);
	if (node != NULL)
	{
		if (node->used != TRUE)
		{
			if (ft_is_tokenpair(node->token) == TRUE)
				ft_extract_quoteseries(node, global);
			else if (ft_is_command(node->token) == TRUE)
				commandname = ft_extract_tokenstring(global->line, node);
		}
	}
	return (commandname);
}
