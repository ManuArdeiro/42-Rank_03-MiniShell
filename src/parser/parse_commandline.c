/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commandline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:24:07 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/28 17:13:16 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_tokensplit_all(
		t_minitree **root, t_part *tokenlist, const char *commandline)
{
	t_token	token;

	token = 0;
	while (token < max_token)
	{
		if (ft_is_tokenseparator(token) == TRUE)
		{
			*root = ft_tokensplit(tokenlist, token);
			if (*root != NULL)
				break ;
		}
		++token;
	}
	if (*root == NULL)
		*root = ft_get_minicommand(commandline, tokenlist);
}

static void	ft_parse_tokenlist(
		t_minitree **root, t_part *tokenlist, const char *commandline)
{
	if (tokenlist == NULL)
		return ;
	ft_tokensplit_all(root, tokenlist, commandline);
	if (ft_is_emptynode((*root)->leftchild) == FALSE)
	{
		ft_parse_tokenlist(
			&(*root)->leftchild,
			((t_mininode *)((*root)->leftchild->content))->content,
			commandline);
	}
	if (ft_is_emptynode((*root)->rightchild) == FALSE)
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
	system("leaks minishell");
	tokenlist = ft_tokenizer((char *)commandline, &token_count);
	system("leaks minishell");
	//ft_print_tokenlist(tokenlist);
	parsetree = ft_generate_parsetree(commandline, tokenlist);
	system("leaks minishell");
	//ft_printtree(parsetree);
	return (parsetree);
}
