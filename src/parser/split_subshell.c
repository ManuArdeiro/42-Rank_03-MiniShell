/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_subshell.c                 			        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:07:46 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/28 20:12:19 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_get_treenode(
		t_minitree **treenode, t_part *startnode, t_mininode *subshell_node)
{
	if ((*treenode) != NULL)
	{
		ft_free_mininode((*treenode)->leftchild->content);
		(*treenode)->leftchild->content = subshell_node;
	}
	else if ((*treenode) == NULL)
		ft_split_tokenlist(&(*treenode), startnode->next);
}

t_minitree	*ft_split_subshell(t_part *tokenlist, t_global *global)
{
	t_part		*startnode;
	t_part		*endnode;
	t_mininode	*subshell_node;
	t_minitree	*treenode;

	treenode = NULL;
	subshell_node = NULL;
	if (tokenlist == NULL)
		return (NULL);
	startnode = ft_get_tokennode(tokenlist, tk_lprnths, TRUE, FIRST);
	endnode = ft_get_tokennode(tokenlist, tk_rprnths, TRUE, LAST);
	if (startnode != NULL && endnode != NULL)
	{
		subshell_node
			= ft_create_mininode(
				ft_get_commandlist(startnode->next, endnode), n_subshell);
		ft_split_tokenlist(&treenode, endnode->next);
		ft_get_treenode(&treenode, startnode, subshell_node);
		if (treenode == NULL)
			treenode = ft_get_minicommand(tokenlist, global);
	}
	return (treenode);
}
