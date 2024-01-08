/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_complete_subshell.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:30:50 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/08 20:44:38 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_complete_subshell(t_part *tokenlist)
{
	t_part	*startnode;
	t_part	*endnode;

	if (tokenlist == NULL)
		return (FALSE);
	startnode = tokenlist;
	if (ft_is_subshellseparator(startnode->token) == TRUE
		|| (startnode->token == tk_space
			&& startnode->next != NULL
			&& ft_is_subshellseparator(startnode->next->token) == TRUE))
	{
		endnode = ft_get_tokennode(startnode->next, tk_rprnths, FALSE, FIRST);
		if (endnode != NULL
			&& (endnode->next == NULL
				|| (endnode->next != NULL && endnode->next->next == NULL)))
			return (TRUE);
	}
	return (FALSE);
}
