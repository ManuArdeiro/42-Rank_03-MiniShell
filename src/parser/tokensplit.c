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

static void	ft_fill_treenode(
		t_minitree **treenode,
		t_part *leftcontent, t_part *rightcontent, t_part *token)
{
	t_mininode	*right;
	t_mininode	*left;
	t_mininode	*separator;

	right = ft_create_mininode((t_part *)rightcontent, ft_get_nodetype(rightcontent));
	left = ft_create_mininode((t_part *)leftcontent, ft_get_nodetype(leftcontent));
	separator = ft_create_mininode(NULL, ft_get_nodetype(token));
	ft_treeinsert(treenode, left, separator, right);
}

t_minitree 	*ft_tokensplit(t_part *tokenlist, t_token token)
{
	t_minitree	*treenode;
	t_part		*node;
	t_part		*delimiter;
	t_part		*nextnode;

	treenode = NULL;
	if (tokenlist == NULL || token <= 0)
		return (NULL);
	node = tokenlist;
	delimiter = ft_get_tokennode(node, token);
	nextnode = ft_get_tokennode(delimiter, token);
	if (delimiter != NULL)
	{
		ft_fill_treenode(
			&treenode,
			ft_get_commandlist(tokenlist, delimiter),
			ft_get_commandlist(delimiter, nextnode),
			delimiter
			);
	}
	return (treenode);
}
