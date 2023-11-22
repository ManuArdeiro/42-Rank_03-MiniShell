/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_arglist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:50:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/28 17:13:16 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	ft_is_argument(t_part *prev_node, t_part *node)
{
	if (node == NULL)
		return (FALSE);
	if ((node->token == tk_arg
		&& (prev_node != NULL && ft_is_redirection(prev_node->token) == FALSE))
		|| node->token == tk_mul)
		return (TRUE);
	return (FALSE);
}

t_list	*ft_extract_arglist(const char *commandline, t_part *tokenlist)
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
	while (node != NULL && ft_is_tokenseparator(node->token) == FALSE)
	{
		if (ft_is_argument(prev_node, node) == TRUE)
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
