/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_validseries.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:42:31 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/27 17:37:27 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_isvalid_series(t_part *node)
{
	if (node == NULL)
		return (FALSE);
	if (node->token != tk_space && node->next != NULL
		&& ft_is_tokenpair(node->next->token) == TRUE)
		return (TRUE);
	else if (node->token == tk_mul
		&& node->next != NULL && node->next->token != tk_space)
		return (TRUE);
	else if (node->token == tk_dollar
		&& node->next != NULL && node->next->token != tk_space)
		return (TRUE);
	else
		if ((ft_is_tokenpair(node->token) == TRUE))
			return (TRUE);
	return (FALSE);
}
