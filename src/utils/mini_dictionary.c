/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_dictionary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:48:16 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/07 17:00:44 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function frees the content memory.	*/

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

/*	This function looks for a passed key in the current environment list 
	and modify it with the passed newvalue.	
	
	Por qué liberas el valor del contenido? No haría falta reservar de nuevo?*/

int	ft_modifydict(t_list **envlist, const char *key, const char *newvalue)
{
	t_list	*node;
	size_t	len;

	if (!envlist || *envlist == NULL || !newvalue)
		return (EXIT_SUCCESS);
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

/*	This function cheks is the received string key is included in the 
	list (envList, the list of strings of environment). 
	
Por qué utilizas size_t, cual es su función en lugar de un int normal? Beneficio?
A qué se expande EXIT y por qué? 
Por qué los paréntesis en ((t_dict *)node->content)->key? 
El nombre de la función no sería mejor ft_search_env? */

int	ft_searchdict(t_list *list, const char *key)
{
	t_list	*node;
	size_t	len;

	if (!list || !key || list->content == NULL)
		return (EXIT_SUCCESS);
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

/*	This funtion creates a new t_dict item (key and value) and adds it to
	the	environment t_dict list.	*/

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

/*	This function checks if the t_dict item (key or value) is empty and
	returns TRUE if so.	It returns FALSE if both key and value are not 
	empty.	*/
	
int	ft_emptydict(t_dict *dict)
{
	if (dict->key == NULL || dict->value == NULL)
		return (TRUE);
	return (FALSE);
}
