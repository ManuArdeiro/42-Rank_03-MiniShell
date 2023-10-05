/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_parsetree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:19:00 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/04 17:41:29 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*typees
- Command list
- subshell
- */
/*Get commnandlist by separator*/
/*Get  by separator*/

static t_minitree	*ft_create_parsetree(
		t_part *tokenlist, t_list *commandsummary)
{
	t_part		*node;
	t_minitree	*treenode;
	t_part		**tokenarray;
	
	node = tokenlist;
	while (node != NULL)
	{
		if (ft_is_logicalseparator(node->token) == TRUE)
			tokenarray = ft_tokensplit(tokenlist, ft_is_logicalseparator);
		//ft_treeinsert(&treenode, /*right, center, left*/);
		node = node->next;
	}
	return (treenode);
}

t_minitree	*ft_generate_parsetree(t_part *tokenlist, t_list *commandsummary)
{
	t_minitree	*parsetree;

	if (tokenlist == NULL || commandsummary == NULL)
		return (NULL);
	parsetree = ft_create_parsetree(tokenlist, commandsummary);
	if (ft_isvalid_commmandtree(parsetree) == FALSE)
		ft_printerror(NULL, "Parser error");
	return (parsetree);
}
