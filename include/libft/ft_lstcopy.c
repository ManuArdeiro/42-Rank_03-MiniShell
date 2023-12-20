/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:43:52 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/20 20:43:54 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcopy(t_list *list, t_list *limit)
{
	t_list	*node;
	t_list	*newlist;

	if (list == NULL)
		return (NULL);
	node = list;
	newlist = NULL;
	while (node != limit)
	{
		ft_lstinsert(&newlist, node->content, BACK);
		node = node->next;
	}
	return (NULL);
}
