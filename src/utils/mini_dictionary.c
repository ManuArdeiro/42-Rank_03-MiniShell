/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_dictionary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:48:16 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/22 18:35:18 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cleardict(void *content)
{
	t_dict	*dict;

	if (content == NULL)
		return ;
	dict = (t_dict *)content;
	if (ft_emptydict(dict) == FALSE && dict != NULL)
	{
		free(dict->key);
		free(dict->value);
		free(dict);
	}
}

int	ft_modifydict(t_list **envlist, const char *key, const char *newvalue)
{
	t_list	*node;
	size_t	len;

	if (!envlist || *envlist == NULL || !newvalue)
		return (EXIT);
	node = *envlist;
	len = ft_strlen(key);
	while (node != NULL)
	{
		if (ft_strncmp(((t_dict *)node->content)->key, key, len) == 0)
		{
			free(((t_dict *)node->content)->value);
			((t_dict *)node->content)->value = NULL;
			((t_dict *)node->content)->value = ft_strdup(newvalue);
			return (TRUE);
		}
		node = node->next;
	}
	return (FALSE);
}

int	ft_searchdict(t_list *list, const char *key)
{
	t_list	*node;
	size_t	len;

	if (!list || !key || list->content == NULL)
		return (EXIT);
	node = list;
	len = ft_strlen(key);
	while (node != NULL)
	{
		if (ft_strncmp(((t_dict *)node->content)->key, key, len) == 0)
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}

void	ft_add_to_dict(t_list **envlist, char *key, char *value)
{
	t_list	*newnode;
	t_dict	*newdict;

	newdict = ft_calloc(sizeof(t_dict), 1);
	if (!newdict)
		return ;
	newdict->key = ft_strdup(key);
	newdict->value = ft_strdup(value);
	newnode = ft_lstnew(newdict);
	ft_lstadd_back(envlist, newnode);
}

int	ft_emptydict(t_dict *dict)
{
	if (dict->key == NULL || dict->value == NULL)
		return (TRUE);
	return (FALSE);
}
