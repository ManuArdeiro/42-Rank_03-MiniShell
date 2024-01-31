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
	if (ft_tokenlist_contains(subtk_list, ft_is_tokenpair) == TRUE)
		commandname
			= ft_get_commandseries(
				global->line, startnode, endnode, global);
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
	startnode = ft_fastforward(tokenlist);
	if (startnode != NULL && startnode->used == FALSE
		&& ft_is_redirection(startnode->token) == TRUE
		&& startnode->next != NULL)
		startnode = ft_skip_redirection(tokenlist);
	endnode = ft_get_last_seriestoken(startnode);
	sub_tklist = ft_copy_tokenlist(startnode, endnode);
	commandname = ft_get_tokenstring(startnode, endnode, sub_tklist, global);
	ft_free_tokenlist(&sub_tklist);
	return (commandname);
}
