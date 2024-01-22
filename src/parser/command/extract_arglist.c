/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_arglist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:50:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/12 21:01:37 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_add_string_tolist(
		t_list **stringlist, const char *string, t_global *global)
{
	if (global->expand_startoken == TRUE
		&& ft_strchr(string, '*') != NULL)
		ft_lstadd_back(stringlist, ft_expand_startoken(string));
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
	global->expand_startoken = TRUE;
	string = ft_extract_tokenstring(global->line, *node);
	if ((*node)->token == tk_arg
		&& (*node)->next != NULL && (*node)->next->token == tk_mul)
		(*node) = (*node)->next;
	return (string);
}

static void	ft_get_arg(
	t_list **stringlist, t_part **node, t_global *global)
{
	char	*string;

	string = NULL;
	if (ft_isvalid_series((*node)) == TRUE)
	{
		string = ft_extractseries((*node), global);
		global->expand_startoken = FALSE;
	}
	if (string == NULL)
	{
		if (((*node)->token == tk_arg) || ((*node)->token == tk_mul))
			string = ft_get_argstring(node, global);
	}
	if (string != NULL)
	{
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
	node = tokenlist;
	while (node != NULL && ft_is_tokenseparator(node->token) == FALSE)
	{
		if (node->used == FALSE)
		{
			ft_get_arg(&stringlist, &node, global);
		}
		if (node != NULL)
			node = node->next;
	}
	return (stringlist);
}
