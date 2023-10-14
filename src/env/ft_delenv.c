/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:09:49 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/12 17:53:53 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*	This function deletes a node from the environmet list if its "key" is equal
	to the key passed as argument.	*/

static int ft_del_node(t_list *envList, char *key)
{
	int		len;
	t_list	*node;
	t_list	*node_next;

	len = ft_strlen(key);
	node = envList;
	node_next = node->next;
	if (ft_strncmp(((t_dict *)node->content)->key, key, len + 1))
	{
		envList = node_next;
		free (node);
		return (EXIT_SUCCESS);
	}
	while (node_next != NULL)
	{	
		if (ft_strncmp(((t_dict *)node_next->content)->key, key, len + 1))
		{
			node->next = node_next->next;
			free(node_next);
			return (EXIT_SUCCESS);
		}
		node = node->next;
		node_next= node_next->next;
	}
	return (EXIT_FAILURE);
}

/*	This function looks for the passed key in the environment list and if it
	is found, then delete that element from the envirnment list.	*/

int	ft_delenv(t_list *envList, char *key)
{
	t_list	*node;
	size_t	len;

	if (!key || envList == NULL)
		return (EXIT_FAILURE);
	len = ft_strlen(key);
	node = envList;
	while (node != NULL)
	{
		if (ft_strncmp(((t_dict *)node->content)->key, key, len + 1) == 0)
		{
			if (ft_del_node(envList, key) == EXIT_SUCCESS)
				return (EXIT_SUCCESS);
			else
				return (EXIT_FAILURE);
		}
		node = node->next;
	}
	return (EXIT_FAILURE);
}