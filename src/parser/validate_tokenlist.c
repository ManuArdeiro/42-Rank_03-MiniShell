/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tokenlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:36:46 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/31 18:41:24 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_validate_tokenlist(t_part *tokenlist)
{
	t_bool	result;
	t_part	*lastnode;

	result = TRUE;
	lastnode = NULL;
	if (tokenlist == NULL)
		return (FALSE);
	if (ft_is_tokenseparator(tokenlist->token) == TRUE
		&& tokenlist->index == 1)
		result = FALSE;
	if (result == TRUE)
	{
		lastnode = ft_get_lasttoken(tokenlist);
		if (lastnode != NULL
			&& (ft_is_tokenseparator(lastnode->token) == TRUE
				|| ft_is_redirection(lastnode->token) == TRUE))
			result = FALSE;
	}
	return (result);
}
