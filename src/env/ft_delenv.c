/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:09:49 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/09 18:39:34 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*	This function deletes a node in the envList if its "key" is equal to the 
	key passed as argument (for nodes not being the first one).	*/

static int	ft_del_node_in_between(t_list *node, char *key)
{
	int	length;

	length = ft_strlen(key);
	while (node)
	{
		if (ft_strncmp(((t_dict *)node->next->content)->key, key, length + 1))
		{
			free(node->next);
			node->next = node->next->next;
			return (EXIT_SUCCESS);
		}
		else
			node = node->next;
	}
	return (EXIT_FAILURE);
}

/*	This function deletes the first node from the environmet list if its
	"key" is equal to the key passed as argument.	*/

static int	ft_del_starting_node(t_list *envList, char *key)
{
	int		len;
	t_list	*node;

	len = ft_strlen(key);
	node = envList;
	if (ft_strncmp(((t_dict *)node->content)->key, key, len + 1) && node->next)
	{
		envList = node->next;
		free (node);
		return (EXIT_SUCCESS);
	}
	else if (ft_strncmp(((t_dict *)node->content)->key, key, len + 1)
		&& !node->next)
	{
		envList = NULL;
		free(node);
		return (EXIT_SUCCESS);
	}
	return (ft_del_node_in_between(node, key));
}

/*	This function looks for the passed key in the environment list and if it
	is found, then delete that element from the envirnment list.	*/

int	ft_delenv(t_list *envList, char *key)
{
	t_list	*node;
	size_t	len;
	char	*result;

	if (!key || envList == NULL)
		return (NULL);
	len = ft_strlen(key);
	node = envList;
	while (node != NULL)
	{
		if (ft_strncmp(((t_dict *)node->content)->key, key, len + 1) == 0)
		{
			if (ft_del_starting_node(envList, key) == EXIT_SUCCESS)
				return (EXIT_SUCCESS);
			else
				return (EXIT_FAILURE);
		}
		node = node->next;
	}
	return (NULL);
}