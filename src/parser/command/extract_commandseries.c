/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_commandseries.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:29:13 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/15 20:48:03 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	ft_check_combination(t_part *node)
{
	if (node == NULL)
		return (FALSE);
	if (node->next != NULL && ft_is_tokenpair(node->next->token) == TRUE
		&& node->next->next != NULL
		&& node->next->next->token != tk_space)
		return (TRUE);
	return (FALSE);
}

static t_cleancase	ft_get_cleancase(t_token token)
{
	if (token == tk_sglquot)
		return (CLEAN_SINGLE_QUOTES);
	else if (token == tk_dblquot)
		return (CLEAN_DOUBLE_QUOTES);
	return (CLEAN_QUOTES);
}

static char	*ft_get_substr(
	const char *commandline,
	t_part *secondnode, t_part **node, t_cleancase cleancase
)
{
	char	*commandseries;
	char	*buffer;

	commandseries = NULL;
	if (secondnode != NULL && secondnode->end > (*node)->start)
	{
		buffer
			= ft_substr(
				commandline,
				(*node)->start,
				((secondnode->end) - ((*node)->start) + 1));
		commandseries = ft_strclean_withspaces(buffer, cleancase);
	}
	return (commandseries);
}

static char	*ft_get_series_substring(const char *commandline, t_part **node)
{
	t_part		*secondnode;
	char		*commandseries;
	t_cleancase	cleancase;

	commandseries = NULL;
	secondnode = NULL;
	if (ft_is_tokenpair((*node)->token) == TRUE)
		secondnode = ft_get_tokennode(
				(*node)->next, ft_get_tokenpair((*node)->token), FALSE, FIRST);
	else if (ft_check_combination(*node) == TRUE)
		secondnode = ft_get_tokennode(
				(*node)->next->next,
				ft_get_tokenpair((*node)->next->token), FALSE, FIRST);
	if (secondnode != NULL
		&& secondnode->next != NULL && secondnode->next->token != tk_space)
		secondnode
			= ft_get_last_seriestoken(
				secondnode,
				ft_get_tokennode(secondnode,
					ft_get_tokenpair(secondnode->token), TRUE, FIRST));
	cleancase = ft_get_cleancase((*node)->token);
	commandseries = ft_get_substr(commandline, secondnode, node, cleancase);
	(*node) = secondnode;
	return (commandseries);
}

char	*ft_extract_commandseries(
	const char *commandline,
	t_part *tokenlist, t_part **nextstart, t_global *global)
{
	t_part	*node;
	char	*commandseries;

	commandseries = NULL;
	if (commandline == NULL || tokenlist == NULL || global == NULL)
		return (NULL);
	node = tokenlist;
	while (node != NULL && commandseries == NULL)
	{
		if ((ft_is_tokenpair(node->token) == TRUE && node->next != NULL)
			|| ((node->token == tk_cmd || node->token == tk_arg)
				&& node->next != NULL
				&&ft_is_tokenpair(node->next->token) == TRUE))
		{
			if (node->token != tk_sglquot)
				global->expand_dollartoken = TRUE;
			commandseries = ft_get_series_substring(commandline, &node);
		}
		if (node != NULL)
			node = node->next;
	}
	if (nextstart != NULL)
		(*nextstart) = node;
	return (commandseries);
}

