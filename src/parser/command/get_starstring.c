/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_starstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:55:18 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/29 20:37:13 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_starstring(t_part **tokenlist, t_global *global)
{
	t_part	*endnode;
	char	*starstring;
	t_part	*startnode;

	starstring = NULL;
	if (tokenlist == NULL)
		return (NULL);
	endnode = *tokenlist;
	if (endnode->token == tk_mul || endnode->token == tk_arg)
		startnode = endnode;
	while (endnode->next != NULL)
	{
		if (endnode->next->token == tk_space)
			break ;
		endnode = endnode->next;
	}
	if (startnode != NULL && endnode != NULL)
	{
		starstring = ft_substr(
				global->line, startnode->start,
				(endnode->end - startnode->start) + 1);
		*tokenlist = endnode;
	}
	return (starstring);
}
