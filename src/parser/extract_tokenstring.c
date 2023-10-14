/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_tokenstring.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:50:43 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/14 21:03:02 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_extract_tokenstring(const char *commandline, t_part *node)
{
	char	*value;

	if (node == NULL || commandline == NULL)
		return (NULL);
	value = NULL;
	value = ft_substr(commandline, node->start, node->end);
	return (value);
}

t_list	*ft_extract_stringlist(
		const char *commandline, t_part *tokenlist, t_token token)
{
	t_part	*node;
	t_list	*stringlist;
	char	*string;

	stringlist = NULL;
	if (!commandline || !tokenlist)
		return (NULL);
	node = tokenlist;
	while (node != NULL && ft_isseparator(node->token) == FALSE)
	{
		if (node->token == token)
		{
			string = ft_extract_tokenstring(commandline, node);
			ft_lstinsert(&stringlist, (char *)string, BACK);
		}
		node = node->next;
	}
	return (stringlist);
}
