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

static char	*ft_get_tokenstring(
		t_part *startnode,
		t_part *endnode, t_part *subtk_list, t_global *global)
{
	char	*commandname;
	t_part	*cmdnode;

	cmdnode = NULL;
	commandname = NULL;
	ft_set_tokenlist(&startnode, endnode, TRUE);
	if (subtk_list == NULL)
		return (NULL);
	if (ft_tokenlist_contains(subtk_list, ft_is_tokenpair) == TRUE
		|| ft_is_backslash_token(subtk_list->token) == TRUE
		|| ft_token_case(subtk_list) == CASE_1)
		commandname = ft_get_commandseries(startnode, endnode, global);
	else if (startnode != NULL && ft_is_dollar(startnode->token) == TRUE)
	{
		commandname = ft_extract_dollarstring(global->line, startnode);
		commandname = ft_expand_dollartoken(commandname, global);
	}
	else
	{
		cmdnode = ft_get_tokennode(startnode, tk_cmd, FALSE, FIRST);
		commandname = ft_extract_tokenstring(global->line, cmdnode);
		global->expand_dollartoken = TRUE;
		commandname = ft_expand_dollartoken(commandname, global);
	}
	return (commandname);
}

static char	*ft_get_stringseries(
	t_part *startnode, t_part *endnode, t_global *global
)
{
	char	*stringseries;
	t_part	*sub_tklist;

	stringseries = NULL;
	sub_tklist = NULL;
	if (endnode != NULL)
	{
		sub_tklist = ft_copy_tokenlist(startnode, endnode->next);
		stringseries
			= ft_get_tokenstring(startnode, endnode->next, sub_tklist, global);
	}
	else
	{
		sub_tklist = ft_copy_tokenlist(startnode, endnode);
		stringseries
			= ft_get_tokenstring(startnode, endnode, sub_tklist, global);
	}
	ft_free_tokenlist(&sub_tklist);
	return (stringseries);
}

static t_bool	ft_is_redirection_list(t_part *head)
{
	t_part	*next;

	if (head == NULL)
		return (FALSE);
	next = head->next;
	if (next != NULL && head->used == FALSE
		&& ft_is_redirection(head->token) == TRUE)
		return (TRUE);
	else if (head->token == tk_space && next != NULL
		&& ft_is_redirection(next->token) == TRUE)
		return (TRUE);
	return (FALSE);
}

char	*ft_extractseries(t_part *tokenlist, t_global *global)
{
	char	*strseries;
	t_part	*startnode;
	t_part	*endnode;

	if (tokenlist == NULL || global == NULL)
		return (NULL);
	strseries = NULL;
	startnode = ft_fastforward(tokenlist);
	if (ft_is_redirection_list(startnode) == TRUE)
		startnode = ft_skip_redirection(tokenlist);
	endnode = ft_get_last_seriestoken(startnode);
	strseries = ft_get_stringseries(startnode, endnode, global);
	return (strseries);
}
