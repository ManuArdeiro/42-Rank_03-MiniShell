/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_strarr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:51:54 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/30 18:07:50 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_lst_to_strarr(t_list *list)
{
	char	**stringarray;
	t_list	*node;
	int		i;

	if (list == NULL)
		return (NULL);
	node = list;
	stringarray = malloc(sizeof(char *) * (ft_lstsize(list) + 1));
	if (!stringarray)
		return (NULL);
	i = 0;
	while (node != NULL)
	{
		stringarray[i] = ft_strdup((char *)node->content);
		node = node->next;
		++i;
	}
	stringarray[i] = NULL;
	return (stringarray);
}

