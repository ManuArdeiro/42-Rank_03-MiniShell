/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_arglist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:50:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/11 21:03:52 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_check_forseries(
		t_part **node, t_part *prevnode, char **string, t_global *global)
{
	if ((*node) == NULL)
		return ;
	if ((prevnode != NULL && ft_is_tokenpair(prevnode->token) == TRUE)
		|| ((*node)->token == tk_arg && (*node)->next != NULL
			&& ft_is_tokenpair((*node)->next->token) == TRUE))
	{
		if (prevnode->token == tk_dblquot)
			global->expand_startoken = FALSE;
		if (prevnode->used == TRUE)
		{
			(*string)
				= ft_extract_commandseries(
					global->line, (*node), node, global);
		}
		else
		{
			prevnode->used = TRUE;
			(*string)
				= ft_extract_commandseries(
					global->line, prevnode, node, global);
		}
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
		ft_lstinsert(stringlist, ft_strdup(string), BACK);
}

static t_bool	ft_is_argument(t_part *node, t_part *prevnode)
{
	t_part	*cmdnode;

	if (node == NULL)
		return (FALSE);
	cmdnode = ft_get_tokennode(node, tk_cmd, FALSE, FIRST);
	if ((prevnode != NULL && ft_is_tokenpair(node->token)
			&& ft_is_tokenpair(prevnode->token))
		|| (ft_is_tokenpair(node->token) == TRUE
			&& ft_tokenlist_contains(node, ft_is_command) == TRUE
			&& cmdnode != NULL && cmdnode->used == FALSE)
		|| (node->token == tk_arg)
		|| (node->token == tk_mul))
		return (TRUE);
	return (FALSE);
}

static void	ft_get_arg(
	t_list **stringlist, t_part **node, t_part *prevnode, t_global *global)
{
	char	*string;

	string = NULL;
	ft_check_forseries(node, prevnode, &string, global);
	if (string == NULL)
	{
		global->expand_dollartoken = TRUE;
		global->expand_startoken = TRUE;
		string = ft_extract_tokenstring(global->line, (*node));
	}
	if (string)
		ft_add_string_tolist(stringlist, string, global);
	free(string);
}

t_list	*ft_extract_arglist(t_part *tokenlist, t_global *global)
{
	t_part	*node;
	t_list	*stringlist;
	t_part	*prevnode;

	stringlist = NULL;
	if (global == NULL || global->line == NULL || !tokenlist)
		return (NULL);
	node = tokenlist;
	prevnode = NULL;
	while (node != NULL && ft_is_tokenseparator(node->token) == FALSE)
	{
		if (ft_is_tokenpair(node->token) == TRUE
			&& ft_is_commandseries(tokenlist) == TRUE)
			node = ft_skip_tokens(node->next, ft_is_tokenpair);
		else if (ft_is_argument(node, prevnode) == TRUE)
			ft_get_arg(&stringlist, &node, prevnode, global);
		if (node != NULL)
		{
			if (node->token != tk_space)
				prevnode = node;
			node = node->next;
		}
	}
	return (stringlist);
}
