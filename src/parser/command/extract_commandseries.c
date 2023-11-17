/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_commandseries.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:29:13 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/16 20:57:20 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_extract_commandseries(const char *commandline, t_part *tokenlist)
{
	t_part	*node;
	t_part	*secondnode;
	char	*commandseries;

	commandseries = NULL;
	if (commandline == NULL || tokenlist == NULL)
		return (NULL);
	node = tokenlist;
	while (node != NULL)
	{
		if (ft_is_tokenpair(node->token) == TRUE)
		{
			secondnode = ft_get_tokennode(node, ft_get_tokenpair(node->token));
			if (secondnode != NULL && secondnode->end > node->start)
				commandseries
					= ft_substr(
						commandline,
						node->start, secondnode->end - node->start + 1);
		}
		node = node->next;
	}
	return (commandseries);
}
