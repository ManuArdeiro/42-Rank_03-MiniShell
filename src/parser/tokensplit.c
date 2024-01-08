/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokensplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:52:43 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/08 19:57:07 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fill_treenode(
		t_minitree **treenode,
		t_part *leftcontent, t_part *rightcontent, t_part *token)
{
	t_mininode	*right;
	t_mininode	*left;
	t_mininode	*separator;
	t_nodetype	nodetype;

	right = ft_create_mininode(
			(t_part *)rightcontent, ft_get_nodetype(rightcontent));
	left = ft_create_mininode(
			(t_part *)leftcontent, ft_get_nodetype(leftcontent));
	nodetype = ft_get_nodetype(token);
	separator = ft_create_mininode(NULL, nodetype);
	ft_treeinsert(treenode, left, separator, right);
}

static void	ft_split_default(
		t_minitree **treenode, t_part *tokenlist, t_token token)
{
	t_part		*delimiter;

	delimiter = skip_get_tokennode(tokenlist, token, TRUE);
	if (delimiter != NULL)
	{
		ft_fill_treenode(
			treenode,
			ft_copy_tokenlist(tokenlist, delimiter),
			ft_copy_tokenlist(delimiter->next, NULL),
			delimiter
			);
	}
}

t_minitree	*ft_tokensplit(t_part *tokenlist, t_token token)
{
	t_minitree	*treenode;

	treenode = NULL;
	if (tokenlist == NULL || token <= 0)
		return (NULL);
	ft_split_default(&treenode, tokenlist, token);
	return (treenode);
}
