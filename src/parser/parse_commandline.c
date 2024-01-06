/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commandline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:24:07 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/05 20:54:29 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_parse_tokenlist(
				t_minitree **root, t_part *tokenlist, t_global *global);

static void	ft_tokensplit_all(
		t_minitree **root, t_part *tokenlist, t_global *global)
{
	if (ft_is_emptynode(*root) == FALSE)
		ft_destroytree(root, ft_free_mininode);
	if (ft_valid_subshellnode(tokenlist) == TRUE)
		*root = ft_split_subshell(tokenlist, global);
	else if (ft_tokenlist_contains(tokenlist, ft_is_tokenseparator) == TRUE)
		ft_split_tokenlist(root, tokenlist);
	else
		*root = ft_get_minicommand(tokenlist, global);
}

static void	ft_parse_tokenlist(
		t_minitree **root, t_part *tokenlist, t_global *global)
{
	t_part	*left_tokenlist;
	t_part	*right_tokenlist;

	left_tokenlist = NULL;
	right_tokenlist = NULL;
	if (tokenlist == NULL)
		return ;
	ft_tokensplit_all(root, tokenlist, global);
	if (*root != NULL && ft_is_emptynode((*root)->leftchild) == FALSE)
	{
		left_tokenlist
			= ((t_mininode *)((*root)->leftchild->content))->content;
		ft_parse_tokenlist(&(*root)->leftchild, left_tokenlist, global);
		if (left_tokenlist != NULL)
			ft_free_tokenlist(&left_tokenlist);
		left_tokenlist = NULL;
	}
	if (*root != NULL && ft_is_emptynode((*root)->rightchild) == FALSE)
	{
		right_tokenlist
			= ((t_mininode *)((*root)->rightchild->content))->content;
		ft_parse_tokenlist(&(*root)->rightchild, right_tokenlist, global);
		if (right_tokenlist != NULL)
			ft_free_tokenlist(&right_tokenlist);
		right_tokenlist = NULL;
	}
}

static t_minitree	*ft_generate_parsetree(t_global *global, t_part *tokenlist)
{
	t_minitree	*parsetree;

	if (tokenlist == NULL)
		return (NULL);
	parsetree = NULL;
	ft_parse_tokenlist(&parsetree, tokenlist, global);
	return (parsetree);
}

t_minitree	*ft_parse_commandline(t_global *global)
{
	t_part		*tokenlist;
	t_minitree	*parsetree;
	int			token_count;

	token_count = 0;
	parsetree = NULL;
	if (global == NULL || (global != NULL && global->line == NULL))
		return (NULL);
	tokenlist = ft_tokenizer(global, &token_count);
	if (global->devmode == TRUE)
		ft_print_tokenlist(tokenlist);
	if (ft_isvalid_commandlist(tokenlist) == TRUE)
		parsetree = ft_generate_parsetree(global, tokenlist);
	else
	{
		if (token_count > 0)
			ft_printerror(NULL, "MiniShell: parser error");
	}
	ft_free_tokenlist(&tokenlist);
	return (parsetree);
}
