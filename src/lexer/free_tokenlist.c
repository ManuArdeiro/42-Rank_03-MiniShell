/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokenlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:07:54 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/28 19:11:50 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_tokenlist(t_part **tokenlist)
{
	t_part	*node;
	t_part	*nextnode;

	if (tokenlist == NULL || (*tokenlist) == NULL)
		return ;
	node = (*tokenlist);
	nextnode = NULL;
	while (node != NULL)
	{
		nextnode = node->next;
		free(node);
		node = nextnode;
	}
}
