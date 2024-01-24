/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tokenlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:36:46 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/24 19:11:35 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_validate_tokenlist(t_part *tokenlist)
{
	int		result;

	result = TRUE;
	if (tokenlist == NULL)
		return (FALSE);
	if (ft_is_tokenseparator(tokenlist->token) == TRUE
		&& tokenlist->index == 1)
		result = FALSE;
	return (result);
}
