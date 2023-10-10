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

static void	ft_add_split_tokens(t_minitree **root, t_part *tokenlist)
{
	ft_tokensplit(root, tokenlist, tk_newline);
	ft_tokensplit(root, tokenlist, tk_and);
	ft_tokensplit(root, tokenlist, tk_or);
	ft_tokensplit(root, tokenlist, tk_lprnths);
	ft_tokensplit(root, tokenlist, tk_pipe);
}

static void	ft_parse_tokenlist(t_minitree **root, t_part *tokenlist)
{
	if (tokenlist == NULL)
		return (NULL);
	
	/*if null fill*/
	/*else checkchild and split tokenlist inside the child and free list*/
	if (root == NULL)
		ft_add_split_tokens(root, tokenlist);
	else
	{
		ft_parse_tokenlist(r);
	}
	return (root);
}

t_minitree	*ft_generate_parsetree(t_part *tokenlist, t_list *commandsummary)
{
	t_minitree	*parsetree;

	if (tokenlist == NULL || commandsummary == NULL)
		return (NULL);
	ft_parse_tokenlist(&parsetree, tokenlist);
	if (ft_isvalid_commmandtree(parsetree) == FALSE)
		ft_printerror(NULL, "Parser error");
	return (parsetree);
}
