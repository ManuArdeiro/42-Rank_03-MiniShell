/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lstnode.c	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:54:28 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/14 19:54:39 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_get_lstnode(t_list *lst, const char *string_tofind)
{
	t_list	*node;

	if (lst == NULL || string_tofind == NULL)
		return (NULL);
	node = lst;
	while (node != NULL)
	{
		if (ft_strcontains((char *)node->content, string_tofind) == TRUE)
			return (node);
		node = node->next;
	}
	return (NULL);
}
