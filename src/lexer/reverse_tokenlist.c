/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tokenlist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:52:43 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/20 20:27:51 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_reverse_tokenlist(t_part **tokenlist)
{
	t_part	*nextnode;
	t_part	*currentnode;
	t_part	*prevnode;

	if ((*tokenlist) == NULL)
		return ;
	nextnode = NULL;
	prevnode = NULL;
	currentnode = (*tokenlist);
	while (currentnode != NULL)
	{
		nextnode = currentnode->next;
		currentnode->next = prevnode;
		prevnode = currentnode;
		currentnode = nextnode;
	}
	(*tokenlist) = prevnode;
}
