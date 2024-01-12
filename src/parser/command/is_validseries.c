/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_validseries.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:42:31 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/12 20:58:08 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_isvalid_series(t_part *node, t_part *prevnode)
{
	(void)prevnode;
	if (node == NULL)
		return (FALSE);
	if (node->token != tk_space && node->next != NULL
		&& ft_is_tokenpair(node->next->token) == TRUE)
		return (TRUE);
	else if (node->token == tk_mul
		&& node->next != NULL && node->next->token != tk_space)
		return (TRUE);
	else
		if ((ft_is_tokenpair(node->token) == TRUE))
			return (TRUE);
	return (FALSE);
}
