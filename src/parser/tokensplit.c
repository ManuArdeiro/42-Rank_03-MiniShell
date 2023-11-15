/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokensplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:52:43 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/11 16:38:57 by yzaytoun         ###   ########.fr       */
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
	t_nodetype	nodetype;

	printf("leftcontent\n");
	ft_print_tokenlist(leftcontent);
	printf("rightcontent\n");
	ft_print_tokenlist(rightcontent);
	right = ft_create_mininode(
			(t_part *)rightcontent, ft_get_nodetype(rightcontent));
	left = ft_create_mininode(
			(t_part *)leftcontent, ft_get_nodetype(leftcontent));
	nodetype = ft_get_nodetype(token);
	separator = ft_create_mininode(NULL, nodetype);
	ft_treeinsert(treenode, left, separator, right);
}

static void	ft_split_default(
		t_minitree **treenode,t_part *tokenlist, t_token token)
{
	t_part		*delimiter;

	delimiter = ft_get_tokennode(tokenlist, token);
	if (delimiter != NULL)
	{
		ft_fill_treenode(
			treenode,
			ft_get_commandlist(tokenlist, delimiter),
			ft_get_commandlist(delimiter->next, NULL),
			delimiter
			);
	}
}

//static t_token	ft_get_tokenpair(t_token token)
//{
//	if (token == tk_lprnths)
//		return (tk_rprnths);
//	else if (token == tk_sglquot)
//		return (tk_sglquot);
//	else if (token == tk_dblquot)
//		return (tk_dblquot);
//	return (token);
//}

//static t_minitree	*ft_split_tokenpair(
//		t_minitree **treenode,t_part *tokenlist, t_token token)
//{
//	t_part		*delimiter;
//	t_part		*nextdelimiter;
//	t_token		secondtoken;
//
//	secondtoken = ft_get_tokenpair(token);
//	delimiter = ft_get_tokennode(tokenlist, token);
//	nextdelimiter = ft_get_tokennode(tokenlist, secondtoken);
//	if (delimiter != NULL)
//	{
//		ft_fill_treenode(
//			&treenode,
//			ft_get_commandlist(tokenlist, delimiter),
//			ft_get_commandlist(delimiter->next, nextdelimiter),
//			delimiter
//			);
//	}
//}

t_minitree	*ft_tokensplit(t_part *tokenlist, t_token token)
{
	t_minitree	*treenode;

	treenode = NULL;
	if (tokenlist == NULL || token <= 0)
		return (NULL);
	//if (splittype == n_subshell)
	//	ft_split_tokenpair(&treenode, tokenlist, token);
	//else
		ft_split_default(&treenode, tokenlist, token);
	return (treenode);
}
