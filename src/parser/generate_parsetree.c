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
t_mininode	*ft_get_separartornode(t_token separatortoken)
{
	t_mininode	*separatornode;

	if (!separatortoken)
		return (NULL);
	separatornode = ft_create_mininode(NULL, separatortoken);
	return (separatornode);
}

void	ft_parsetree_add(t_minitree *parsetree, t_list *tokenarray)
{
	t_list		*node;
	t_mininode	*separator;

	if (tokenarray == NULL)
		return ;
	separator = ft_get_separatornode(((t_mininode *)node->content)->type);
	if (separator == NULL)
		ft_printerror(__func__, "No separator token");
	while (node != NULL)
	{
		ft_treeinsert(
			(t_mininode *)node->content,
			separator,
			(t_mininode *)node->next->content
			);
		node = node->next;
	}
	node = tokenarray;
}

// Create function to add list to tree
static t_minitree	*ft_create_parsetree(
		t_part *tokenlist, t_list *commandsummary)
{
	t_minitree	*parsetree;
	t_list		*tokenarray;

	tokenarray = ft_tokensplit(tokenlist, ft_is_subshellseparator, n_subshell);
	ft_parsetree_add(&parsetree, tokenarray);
	ft_tokensplit(&parsetree, tokenlist, ft_is_subshellseparator, n_and_if);
	ft_tokensplit(&parsetree, tokenlist, ft_is_subshellseparator, n_or_if);
	ft_tokensplit(&parsetree, tokenlist, ft_is_subshellseparator, n_pipe_sequence);
	ft_tokensplit(&parsetree, tokenlist, ft_is_subshellseparator, n_pipeline);
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
