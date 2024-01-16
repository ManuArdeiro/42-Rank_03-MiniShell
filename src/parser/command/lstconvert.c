/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstconvert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:51:54 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/23 19:41:17 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_dict_to_str(t_dict *dict)
{
	(void)dict;
	//
	char	*string;
	string = NULL;
	return (string);
}

static char	**ft_empty_strarr(void)
{
	char	**stringarray;

	stringarray = malloc(sizeof(char *) * 2);
	if (stringarray == NULL)
		return (NULL);
	stringarray[0] = "";
	stringarray[1] = NULL;
	return (stringarray);
}

char	**ft_lstconvert_strarr(t_list *list, t_bool type)
{
	char	**stringarray;
	t_list	*node;
	char	*string;
	int		i;

	if (list == NULL)
		return (ft_empty_strarr());
	node = list;
	stringarray = malloc(sizeof(char *) * (ft_lstsize(list) + 1));
	if (!stringarray)
		return (NULL);
	i = 0;
	while (node != NULL)
	{
		if (type == ENV)
			string = ft_dict_to_str((t_dict *)node->content);
		else
			string = (char *)node->content;
		if (string != NULL)
			stringarray[i] = ft_strdup(string);
		node = node->next;
		++i;
	}
	stringarray[i] = NULL;
	return (stringarray);
}
