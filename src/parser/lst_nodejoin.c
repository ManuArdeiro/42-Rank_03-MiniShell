/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_nodejoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:00:38 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/25 13:36:48 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	ft_get_tokentype(const char *string)
{
	if (string == NULL)
		return (EXITED);
	else if (ft_strchr(string, '\'') != NULL)
		return (tk_sglquot);
	else if (ft_strchr(string, '\"') != NULL)
		return (tk_dblquot);
	return (0);
}

static void	ft_join_prevnode(t_list *node, t_list *prev_node, t_token token)
{
	char	*string;

	string = ft_strtrim((char *)prev_node->content, "\'\"");
	if (string != NULL)
	{
		prev_node->next = node->next;
		ft_free_string(prev_node->content);
		if (token == tk_dblquot)
			prev_node->content = ft_strjoin_get(string, (char *)node->content);
		else if (token == tk_sglquot)
			prev_node->content = ft_strdup((char *)node->content);
		ft_free_string(node->content);
		free(node);
		if (token == tk_sglquot)
			free(string);
	}
}

static void	ft_join_nextnode(t_list *node, t_token token)
{
	char	*string;
	t_list	*pointer;

	pointer = NULL;
	string = ft_strtrim((char *)node->content, "\'\"");
	if (string != NULL)
	{
		ft_free_string(node->content);
		if (node->next != NULL)
		{
			pointer = node->next->next;
			if (token == tk_dblquot)
				node->content
					= ft_strjoin_get(string, (char *)node->next->content);
			else if (token == tk_sglquot)
				node->content = ft_strdup((char *)node->next->content);
			ft_free_string(node->next->content);
			free(node->next);
			node->next = pointer;
		}
		if (token == tk_sglquot)
			free(string);
	}
}

void	ft_lst_nodejoin(t_list *prev_node, t_list *node)
{
	t_token	token;

	token = 0;
	token = ft_get_tokentype((char *)node->content);
	if (prev_node != NULL && node != NULL)
		ft_join_prevnode(node, prev_node, token);
	else
		ft_join_nextnode(node, token);
}
