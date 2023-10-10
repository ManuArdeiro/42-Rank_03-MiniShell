/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_parsetree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:19:00 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/04 17:12:02 by yzaytoun         ###   ########.fr       */
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
		t_list *commandlist, t_list *commandsummary)
{
	t_list		*node;
	t_minitree	*treenode;

	node = commandlist;
	while (node != NULL)
	{
		
		ft_treeinsert(&treenode, /*right, center, left*/);
		node = node->next;
	}
	return (treenode);
}

t_minitree	*ft_generate_parsetree(t_list *commandlist, t_list *commandsummary)
{
	t_minitree	*parsetree;

	if (commandlist == NULL || commandsummary == NULL)
		return (NULL);
	parsetree = ft_create_parsetree(commandlist, commandsummary);
	if (ft_isvalid_commmandtree(parsetree) == FALSE)
		ft_printerror(NULL, "Parser error");
	return (parsetree);
}
