/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lasttoken.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:29:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/20 20:29:50 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_part	*ft_get_lasttoken(t_part *tokenlist)
{
	t_part	*last;

	if (tokenlist == NULL)
		return (NULL);
	last = tokenlist;
	while (last->next != NULL)
		last = last->next;
	return (last);
}
