/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokensplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:52:43 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/09 19:17:34 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_tokensplit(
	t_minitree **parsetree,
	t_part *tokenlist, t_bool (*splitfunction)(t_token), t_nodetype nodetype)
{
	t_part	*node;
	t_part	*leftlist;
	t_part	*rightlist;

	if (tokenlist == NULL)
		return (NULL);
	node = tokenlist;
	leftlist = NULL;
	rightlist = NULL;
	while (node != NULL)
	{
		if ((*splitfunction)(node->token) == TRUE && node->used == FALSE)
		{
			node->used = TRUE;
			mininode = ft_create_mininode(NULL, nodetype);
			parsetree = ft_create_treenode(mininode);
			ft_copy_tokenlist(&leftlist, tokenlist, node, LEFT);
			mininode = ft_create_mininode((t_list *) leftlist, nodetype);
			parsetree->leftchild = ft_insertleft(mininode);
			ft_copy_tokenlist(&rightlist, tokenlist, node, RIGHT);
			mininode = ft_create_mininode((t_list *) rightlist, nodetype);
			parsetree->righttchild = ft_insertright(mininode);
		}
		node = node->next;
	}
}
