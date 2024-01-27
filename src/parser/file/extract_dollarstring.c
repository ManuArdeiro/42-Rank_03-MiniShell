/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_dollarstring.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:54:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/27 20:14:41 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_extract_dollarstring(const char *commandline, t_part *tokenlist)
{
	t_part	*node;
	t_part	*startnode;
	char	*dollstring;

	if (tokenlist == NULL)
		return (NULL);
	dollstring = NULL;
	startnode = NULL;
	node = tokenlist;
	while (node->next != NULL
		&& ft_is_tokenseparator(node->next->token) == FALSE
		&& node->next->token != tk_space)
	{
		if (node->token == tk_dollar)
			startnode = node;
		node = node->next;
	}
	if (node != NULL && startnode != NULL)
	{
		ft_set_tokenlist(&startnode, node, TRUE);
		dollstring = ft_substr(commandline, startnode->start,
				((node->end) - (startnode->start) + 1));
	}
	return (dollstring);
}
