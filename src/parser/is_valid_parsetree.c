/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_parsetree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:36:59 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/13 20:57:07 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_check_commandlist(t_minitree *root, t_bool *flag)
{
	
}

static void	ft_check_grammar(t_minitree *root, t_bool *flag)
{
	
}

static void	ft_treecheck(
	t_minitree *root, void (*function)(t_minitree *, t_bool *), t_bool *flag)
{
	if (root == NULL)
		return ;
	(*function)(root, flag);
	if (ft_is_emptynode(root->leftchild) == FALSE)
		(*function)(root->leftchild, flag);
	if (ft_is_emptynode(root->rightchild) == FALSE)
		(*function)(root->rightchild, flag);
}


t_bool	ft_is_valid_parsetree(t_minitree *root)
{
	t_bool	is_valid;

	is_valid = FALSE;
	if (root == NULL)
		return (FALSE);
	ft_treeapply(root, ft_check_grammar, &is_valid);
	ft_treeapply(root, ft_check_commandlist, &is_valid);
	return (is_valid);
}