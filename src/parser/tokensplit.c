/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokensplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:52:43 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/13 16:31:15 by yzaytoun         ###   ########.fr       */
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

	right = ft_create_mininode(
			(t_part *)rightcontent, ft_get_nodetype(rightcontent));
	left = ft_create_mininode(
			(t_part *)leftcontent, ft_get_nodetype(leftcontent));
	separator = ft_create_mininode(NULL, ft_get_nodetype(token));
	ft_treeinsert(treenode, left, separator, right);
}

t_minitree	*ft_tokensplit(t_part *tokenlist, t_token token)
{
	t_minitree	*treenode;
	t_part		*delimiter;
	t_part		*nextdelimiter;
	t_part		*nextnode;

	treenode = NULL;
	if (tokenlist == NULL || token <= 0)
		return (NULL);
	delimiter = ft_get_tokennode(tokenlist, token, CURRENT_NODE);
	nextdelimiter = ft_get_tokennode(delimiter, token, CURRENT_NODE);
	nextnode = ft_get_tokennode(tokenlist, token, NEXT_NODE);
	if (delimiter != NULL)
	{
		ft_fill_treenode(
			&treenode,
			ft_get_commandlist(tokenlist, delimiter),
			ft_get_commandlist(nextnode, nextdelimiter),
			delimiter
			);
	}
	return (treenode);
}
