/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_parsetree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:19:00 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/10 17:56:49 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_tokensplit_all(t_minitree **root, t_part *tokenlist)
{
	*root = ft_tokensplit(tokenlist, tk_newline);
	if (*root == NULL)
		*root = ft_tokensplit(tokenlist, tk_and);
	if (*root == NULL)
		*root = ft_tokensplit(tokenlist, tk_or);
	if (*root == NULL)
		*root = ft_tokensplit(tokenlist, tk_lprnths);
	if (*root == NULL)
		*root = ft_tokensplit(tokenlist, tk_pipe);

}

static void	ft_parse_tokenlist(t_minitree **root, t_part *tokenlist)
{
	if (tokenlist == NULL)
		return ;
	if (*root == NULL)
		ft_tokensplit_all(root, tokenlist);
	else
	{
		free(*root);
		ft_tokensplit_all(root, tokenlist);
	}
	if (*root)
	{
		ft_parse_tokenlist(&(*root)->leftchild, (t_part *)(*root)->leftchild->content);
		ft_parse_tokenlist(&(*root)->rightchild, (t_part *)(*root)->rightchild->content);
	}
}

t_minitree	*ft_generate_parsetree(t_part *tokenlist, t_list *commandsummary)
{
	t_minitree	*parsetree;

	if (tokenlist == NULL || commandsummary == NULL)
		return (NULL);
	ft_parse_tokenlist(&parsetree, tokenlist);
	//if (ft_isvalid_commmandtree(parsetree) == FALSE)
	//	ft_printerror(NULL, "Parser error");
	return (parsetree);
}
