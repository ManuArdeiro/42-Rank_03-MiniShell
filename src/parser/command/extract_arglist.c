/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_arglist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:50:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/19 18:35:52 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_check_forseries(
		t_part **node, char **string, t_global *global)
{
	if ((*node) == NULL)
		return ;
	if (ft_is_tokenpair((*node)->token) == TRUE
		|| ((*node)->next != NULL
			&& ft_is_tokenpair((*node)->next->token) == TRUE))
	{
		if ((*node)->token == tk_dblquot)
			global->expand_startoken = FALSE;
		(*string)
			= ft_extract_commandseries(
				global->line, (*node), node, global);
	}
}

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
		ft_lstinsert(stringlist, (char *)string, BACK);
}

static t_bool	ft_is_argument(t_part *node)
{
	if (node == NULL)
		return (FALSE);
	if ((ft_is_tokenpair(node->token) == TRUE)
		|| (node->token == tk_arg)
		|| (node->token == tk_mul))
		return (TRUE);
	return (FALSE);
}

static void	ft_get_arg(
	t_list **stringlist, t_part **node, t_global *global)
{
	char	*string;

	string = NULL;
	ft_check_forseries(node, &string, global);
	if (string == NULL)
	{
		global->expand_dollartoken = TRUE;
		global->expand_startoken = TRUE;
		string = ft_extract_tokenstring(global->line, (*node));
	}
	if (string)
		ft_add_string_tolist(stringlist, string, global);
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
		if (ft_is_tokenpair(node->token) == TRUE
			&& ft_is_commandseries(tokenlist) == TRUE)
			ft_skip_quotes(&node->next);
		else if (ft_is_argument(node) == TRUE)
			ft_get_arg(&stringlist, &node, global);
		if (node != NULL)
			node = node->next;
	}
	return (stringlist);
}
