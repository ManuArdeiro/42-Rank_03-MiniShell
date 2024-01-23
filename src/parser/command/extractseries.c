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

static char	*ft_get_tokenstring(
		t_part *startnode
		,t_part *endnode, t_part *subtk_list, t_global *global)
{
	char	*commandname;
	t_part	*cmdnode;

	cmdnode = NULL;
	commandname = NULL;
	ft_set_tokenlist(&startnode, endnode, TRUE);
	if (ft_tokenlist_contains(subtk_list, ft_is_tokenpair) == TRUE)
		commandname
			= ft_get_commandseries(
				global->line, startnode, endnode, global);
	else
	{
		cmdnode = ft_get_tokennode(startnode, tk_cmd, FALSE, FIRST);
		commandname = ft_extract_tokenstring(global->line, cmdnode);
		global->expand_dollartoken = TRUE;
		commandname = ft_expand_dollartoken(commandname, global);
	}
	return (commandname);
}

char	*ft_extractseries(t_part *tokenlist, t_global *global)
{
	char	*commandname;
	t_part	*startnode;
	t_part	*endnode;
	t_part	*sub_tklist;

	if (tokenlist == NULL || global == NULL)
		return (NULL);
	commandname = NULL;
	sub_tklist = NULL;
	startnode = ft_get_startnode(tokenlist);
	if (startnode != NULL && startnode->used == FALSE
		&& ft_is_redirection(startnode->token) == TRUE
		&& startnode->next != NULL)
		startnode = ft_skip_redirection(tokenlist);
	endnode = ft_get_last_seriestoken(startnode);
	sub_tklist = ft_copy_tokenlist(startnode, endnode);
	commandname = ft_get_tokenstring(startnode, endnode, sub_tklist, global);
	return (commandname);
}
