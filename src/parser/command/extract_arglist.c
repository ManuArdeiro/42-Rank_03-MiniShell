/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_arglist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:50:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/31 20:29:08 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_add_string_tolist(
		t_list **stringlist, const char *string, t_global *global)
{
	t_list	*expandedlist;
	t_list	*node;

	expandedlist = NULL;
	if (global->expand_startoken == TRUE
		&& ft_strchr(string, '*') != NULL)
	{
		expandedlist = ft_expand_startoken(string);
		node = expandedlist;
		while (node != NULL)
		{
			ft_lstinsert(stringlist, node->content, BACK);
			node = node->next;
		}
		ft_lstclear_nodes(&expandedlist);
	}
	else if (global->expand_dollartoken == TRUE
		&& ft_strchr(string, '$') != NULL)
		ft_lstinsert(stringlist,
			ft_expand_dollartoken(string, global), BACK);
	else
		ft_lstinsert(stringlist, ft_strdup(string), BACK);
}

static char	*ft_get_argstring(t_part **node, t_global *global)
{
	char	*string;

	string = NULL;
	global->expand_dollartoken = TRUE;
	string = ft_extract_tokenstring(global->line, *node);
	return (string);
}

static void	ft_get_arg(
	t_list **stringlist, t_part **node, t_global *global)
{
	char	*string;

	string = NULL;
	if (ft_token_case(*node) == CASE_1)
		string = ft_extractseries((*node), global);
	else if (ft_token_case(*node) == CASE_4)
		string = ft_get_starstring(node, global);
	else if (ft_token_case(*node) == CASE_3)
	{
		global->expand_dollartoken = TRUE;
		string = ft_extract_dollarstring(global->line, *node);
	}
	if (string == NULL && ft_token_case(*node) == CASE_2)
		string = ft_get_argstring(node, global);
	if (string != NULL)
	{
		global->expand_startoken = TRUE;
		ft_add_string_tolist(stringlist, string, global);
		free(string);
	}
}

t_list	*ft_extract_arglist(t_part *tokenlist, t_global *global)
{
	t_part	*node;
	t_list	*stringlist;

	stringlist = NULL;
	if (global == NULL || global->line == NULL || !tokenlist)
		return (NULL);
	node = ft_skip_redirection(tokenlist);
	node = ft_fastforward(node);
	while (node != NULL && ft_is_tokenseparator(node->token) == FALSE)
	{
		if (node->used == FALSE && node->token != tk_space)
			ft_get_arg(&stringlist, &node, global);
		if (node != NULL)
			node = node->next;
	}
	return (stringlist);
}
