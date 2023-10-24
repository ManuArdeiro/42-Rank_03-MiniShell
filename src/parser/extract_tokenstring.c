/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_tokenstring.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:50:43 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/24 20:51:28 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_extract_tokenstring(const char *commandline, t_part *node)
{
	char	*value;

	if (node == NULL || commandline == NULL)
		return (NULL);
	value = NULL;
	value = ft_substr(commandline, node->start, (node->end - node->start) + 1);
	return (value);
}

t_list	*ft_extract_argumentlist(const char *commandline, t_part *tokenlist)
{
	t_part	*node;
	t_part	*prev_node;
	t_list	*stringlist;
	char	*string;

	stringlist = NULL;
	if (!commandline || !tokenlist)
		return (NULL);
	node = tokenlist;
	prev_node = NULL;
	while (node != NULL && ft_isseparator(node->token) == FALSE)
	{
		if ((node->token == tk_arg || node->token == tk_mul)
			&& ft_is_redirection(prev_node->token) == FALSE)
		{
			string = ft_extract_tokenstring(commandline, node);
			if (ft_strchr(string, '*') != NULL)
				ft_lstadd_back(&stringlist, ft_expand_startoken(string));
			else
				ft_lstinsert(&stringlist, (char *)string, BACK);
		}
		prev_node = node;
		node = node->next;
	}
	return (stringlist);
}
