/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_emptyquotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:48:06 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/22 19:51:04 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_is_emptyquotes(t_part *startnode, t_part *endnode)
{
	if (endnode == NULL)
		return (FALSE);
	if (ft_is_tokenpair(endnode->token) == TRUE
		&& ft_is_tokenpair(startnode->token) == TRUE
		&& endnode->index == startnode->index + 1)
		return (TRUE);
	return (FALSE);
}
