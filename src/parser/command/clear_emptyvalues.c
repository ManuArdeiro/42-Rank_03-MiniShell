/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_emptyvalues.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:38:32 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/05 20:05:22 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_clear_emptyvalues(t_list *list)
{
	t_list	*cleanlist;
	t_list	*node;

	if (list == NULL)
		return (NULL);
	cleanlist = NULL;
	node = list;
	while (node != NULL)
	{
		if (ft_strlen((char *)node->content) > 0)
			ft_lstinsert(&cleanlist, ft_strdup((char *)node->content), BACK);
		node = node->next;
	}
	ft_lstclear(&list, free);
	list = NULL;
	return (cleanlist);
}
