/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_commandseries.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:29:13 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/11 20:37:33 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_series_substring(
		const char *commandline, t_part **node, t_global *global)
{
	t_part		*secondnode;
	char		*commandseries;

	commandseries = NULL;
	secondnode = NULL;
	secondnode = ft_get_last_seriestoken((*node));
	commandseries
		= ft_get_commandseries(commandline, (*node), secondnode, global);
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
		if ((ft_is_tokenpair(node->token) == TRUE
				&& node->used == FALSE && node->next != NULL)
			|| ((node->token == tk_cmd || node->token == tk_arg)
				&& node->next != NULL
				&&ft_is_tokenpair(node->next->token) == TRUE))
			commandseries = ft_get_series_substring(commandline, &node, global);
		if (node != NULL)
			node = node->next;
	}
	if (nextstart != NULL)
		(*nextstart) = node;
	return (commandseries);
}
