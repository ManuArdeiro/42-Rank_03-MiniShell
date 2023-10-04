/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_parsetree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:19:00 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/04 13:18:26 by yzaytoun         ###   ########.fr       */
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
	int	sep_count;

	sep_count = ft_get_tokencount(commandsummary, tk_and);
	sep_count = ft_get_tokencount(commandsummary, tk_or);
	/*if separator == TRUE
	get separator and the two commands
	*/
	while (sep_count > 0)
	{
		ft_treeinsert(/*right, center, left*/);
		sep_count--;
	}
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
