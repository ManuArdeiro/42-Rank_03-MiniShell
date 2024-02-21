/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commandline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:24:07 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/21 19:31:53 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minitree	*ft_parse_tokenlist(t_part *tokenlist, t_global *global);

t_minitree	*ft_evaluate_tokensplit(t_part *tokenlist, t_global *global)
{
	t_minitree	*root;

	root = NULL;
	if (is_complete_subshell(tokenlist) == FALSE
		&& ft_skip_tokenlist_contains(tokenlist, ft_is_tokenseparator) == TRUE)
		root = ft_split_tokenlist(tokenlist);
	else if (ft_valid_subshellnode(tokenlist) == TRUE)
		root = ft_split_subshell(tokenlist, global);
	if (root == NULL)
		root = ft_get_minicommand(tokenlist, global);
	return (root);
}

t_minitree	*replace_treenode(t_minitree *root, t_global *global)
{
	t_part		*tokenlist_copy;
	t_minitree	*new_root;

	new_root = NULL;
	tokenlist_copy
		= ft_copy_tokenlist(
			(t_part *)((t_mininode *)root->content)->content, NULL);
	ft_destroytree(&root, ft_free_mininode);
	new_root = ft_parse_tokenlist(tokenlist_copy, global);
	if (tokenlist_copy != NULL)
		ft_free_tokenlist(&tokenlist_copy);
	return (new_root);
}

t_minitree	*ft_parse_tokenlist(t_part *tokenlist, t_global *global)
{
	t_minitree	*minitree;

	if (tokenlist == NULL)
		return (NULL);
	minitree = NULL;
	minitree = ft_evaluate_tokensplit(tokenlist, global);
	if (minitree != NULL && ft_is_emptynode(minitree->leftchild) == FALSE)
		minitree->leftchild = replace_treenode(minitree->leftchild, global);
	if (minitree != NULL && ft_is_emptynode(minitree->rightchild) == FALSE)
		minitree->rightchild = replace_treenode(minitree->rightchild, global);
	return (minitree);
}

static t_minitree	*ft_generate_parsetree(t_global *global, t_part *tokenlist)
{
	t_minitree	*parsetree;

	parsetree = NULL;
	if (tokenlist != NULL)
		parsetree = ft_parse_tokenlist(tokenlist, global);
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
