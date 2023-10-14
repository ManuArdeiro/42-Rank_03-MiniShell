/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstconvert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:51:54 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/14 16:37:50 by yzaytoun         ###   ########.fr       */
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

static t_file	*ft_create_filearray(size_t size, int std_stream)
{
	t_file	*filearray;

	filearray = NULL;
	filearray = malloc(sizeof(t_file) * (size + 1));
	if (!filearray)
		return (NULL);
	else if (filearray)
	{
		if (size == 0)
		{
			filearray[0].name = NULL;
			filearray[0].fd = std_stream;
		}
		else
		{
			filearray[size + 1].name = NULL;
			filearray[size + 1].fd = std_stream;
		}
	}
	return (filearray);
}

t_file	*ft_lstconvert_filearr(t_list *list, int std_stream)
{
	t_file	*filearray;
	t_list	*node;
	int		i;

	if (list == NULL)
		filearray = ft_create_filearray(0, std_stream);
	node = list;
	filearray = ft_create_filearray(ft_lstsize(list), std_stream);
	if (filearray)
	{
		i = 0;
		while (node != NULL)
		{
			filearray[i].name = ft_strdup((char *)node->content);
			filearray[i].fd = std_stream;
			node = node->next;
			++i;
		}
	}
	return (filearray);
}

