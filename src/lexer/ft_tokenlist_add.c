/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenlist_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:27:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/11 12:08:31 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_tokenlist_add(t_part **tokenlist, t_part *newtoken)
{
	t_part	*last;

	if (*tokenlist == NULL)
		*tokenlist = newtoken;
	else
	{
		last = (*tokenlist);
		while (last->next != NULL)
			last = last->next;
		last->next = newtoken;
	}
}
