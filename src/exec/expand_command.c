/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:22:10 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/30 20:07:06 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_expand_node(
	t_list *node, t_list *prev_node, t_list *envlist, int laststatus)
{
	char	*dollar_expansion;

	dollar_expansion = NULL;
	if (node == NULL)
		return ;
	dollar_expansion
		= ft_expand_dollartoken(
			(char *)node->content, envlist, laststatus);
	if (dollar_expansion != NULL
		&& (char *)node->content != dollar_expansion)
	{
		free(node->content);
		node->content = dollar_expansion;
	}
}

static void	ft_expandlist(
		t_list **list, t_list *envlist, int laststatus)
{
	t_list	*node;
	t_list	*prev_node;

	node = (*list);
	prev_node = NULL;
	while (node != NULL)
	{
		ft_expand_node(node, prev_node, envlist, laststatus);
		prev_node = node;
		node = node->next;
	}
}

void	ft_expand_command(t_command *command, t_global *global)
{
	char	*dollarexpansion;

	dollarexpansion = NULL;
	dollarexpansion = ft_expand_dollartoken(
			command->name, global->envlist, global->laststatus);
	if (dollarexpansion == NULL)
		command->name = ft_strdup("");
	else
		command->name = dollarexpansion;
	ft_expandlist(&command->args, global->envlist, global->laststatus);
	ft_expandlist(&command->infile, global->envlist, global->laststatus);
	ft_expandlist(&command->outfile, global->envlist, global->laststatus);
}
