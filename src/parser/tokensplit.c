/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokensplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:52:43 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/10 17:41:36 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_add_to_parsetree(
		t_minitree **parsetree,
		t_part *leftcontent, t_part *rightcontent, t_part *token)
{
	t_mininode	*right;
	t_mininode	*left;
	t_mininode	*separator;

	right = ft_create_mininode(rightcontent, ft_get_nodetype(rightcontent));
	left = ft_create_mininode(leftcontent, ft_get_nodetype(leftcontent));
	separator = ft_create_mininode(NULL, ft_get_nodetype(token));
	ft_treeinsert(parsetree, left, separator, right);
}

void	ft_tokensplit(
	t_minitree **parsetree, t_part *tokenlist, t_token token)
{
	t_part	*node;
	t_part	*delimiter;
	t_part	*nextnode;

	if (tokenlist == NULL || token <= 0)
		return (NULL);
	node = tokenlist;
	while (node != NULL)
	{
		delimiter = ft_get_tokennode(node, token);
		nextnode = ft_get_tokennode(delimiter, token);
		if (delimiter != NULL)
		{
			ft_add_to_parsetree(
				parsetree,
				ft_get_commandlist(tokenlist, delimiter),
				ft_get_commandlist(delimiter, nextnode),
				delimiter
				);
		}
		node = node->next;
	}
}
