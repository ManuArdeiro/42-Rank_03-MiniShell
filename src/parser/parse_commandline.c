/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commandline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:24:07 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/30 18:28:40 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_tokensplit_all(
		t_minitree **root, t_part *tokenlist, const char *commandline)
{
	t_token		token;
	t_minitree	*newnode;

	token = 0;
	newnode = NULL;
	if (ft_contains_tokenseparator(tokenlist) == TRUE)
	{
		while (token < max_token)
		{
			if (ft_is_tokenseparator(token) == TRUE)
			{
				newnode = ft_tokensplit(tokenlist, token);
				if (newnode != NULL)
				{
					if (ft_is_emptynode(*root) == FALSE)
						ft_destroytree(root, ft_free_mininode);
					*root = newnode;
					break ;
				}
			}
			++token;
		}
	}
	else
		*root = ft_get_minicommand(commandline, tokenlist);
}

static void	ft_parse_tokenlist(
		t_minitree **root, t_part *tokenlist, const char *commandline)
{
	if (tokenlist == NULL)
		return ;
	ft_tokensplit_all(root, tokenlist, commandline);
	if (*root != NULL
		&& ft_is_emptynode((*root)->leftchild) == FALSE)
	{
		ft_parse_tokenlist(
			&(*root)->leftchild,
			((t_mininode *)((*root)->leftchild->content))->content,
			commandline);
	}
	if (*root != NULL
		&& ft_is_emptynode((*root)->rightchild) == FALSE)
	{
		ft_parse_tokenlist(
			&(*root)->rightchild,
			((t_mininode *)((*root)->rightchild->content))->content,
			commandline);
	}
}

static t_minitree	*ft_generate_parsetree(
		const char *commandline, t_part *tokenlist)
{
	t_minitree	*parsetree;

	if (tokenlist == NULL)
		return (NULL);
	parsetree = NULL;
	ft_parse_tokenlist(&parsetree, tokenlist, commandline);
	return (parsetree);
}

t_minitree	*ft_parse_commandline(const char *commandline)
{
	t_part		*tokenlist;
	t_minitree	*parsetree;
	int			token_count;

	token_count = 0;
	parsetree = NULL;
	if (commandline == NULL)
		return (NULL);
	tokenlist = ft_tokenizer((char *)commandline, &token_count);
	//ft_print_tokenlist(tokenlist);
	parsetree = ft_generate_parsetree(commandline, tokenlist);
	ft_free_tokenlist(&tokenlist);
	//ft_printtree(parsetree);
	return (parsetree);
}
