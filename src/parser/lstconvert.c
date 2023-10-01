/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstconvert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:51:54 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/01 16:17:01 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_lstconvert_strarr(t_list *list)
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

t_file	*ft_lstconvert_filearr(t_list *list)
{
	t_file	*filearray;
	t_list	*node;
	int		i;

	if (list == NULL)
		return (NULL);
	node = list;
	filearray = malloc(sizeof(t_file) * (ft_lstsize(list) + 1));
	if (!filearray)
		return (NULL);
	i = 0;
	while (node != NULL)
	{
		filearray[i].name = ft_strdup((char *)node->content);
		filearray[i].fd = 0;
		node = node->next;
		++i;
	}
	filearray[i].name = NULL;
	return (filearray);
}

