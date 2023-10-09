/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_parsetree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:19:00 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/09 19:13:57 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_mininode	*ft_get_separartornode(t_token separatortoken)
{
	t_mininode	*separatornode;

	if (!separatortoken)
		return (NULL);
	separatornode = ft_create_mininode(NULL, separatortoken);
	return (separatornode);
}

static t_minitree	*ft_create_parsetree(
		t_part *tokenlist, t_list *commandsummary)
{
	t_minitree	*parsetree;
	t_minitree	*treenode;

	ft_tokensplit(&parsetree, tokenlist, ft_is_subshellseparator, n_subshell);
	//ft_tokensplit(tokenlist, ft_is_logicalseparator, n_and_if);
	//ft_tokensplit(tokenlist, ft_is_pipeseparator, n_pipeline);
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
