/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:09:49 by jolopez-          #+#    #+#             */
/*   Updated: 2023/12/20 20:32:12 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function deletes a node from the environmet list if its "key" is equal
	to the key passed as argument.	*/

static int	ft_del_node(t_list *prev_node, t_list *node)
{
	t_list	*pointer;

	pointer = node;
	if (node != NULL && prev_node != NULL)
	{
		prev_node->next = node->next;
		free(node);
		return (EXIT_SUCCESS);
	}
	else if (node != NULL)
	{
		pointer = node->next;
		free(node);
		node = pointer;
	}
	return (EXIT_FAILURE);
}

/*	This function looks for the passed key in the environment list and if it
	is found, then delete that element from the envirnment list.	*/

int	ft_delenv(t_list *envList, char *key)
{
	t_list	*node;
	t_list	*prev_node;

	if (!key || envList == NULL)
		return (EXIT_FAILURE);
	prev_node = NULL;
	node = envList;
	while (node != NULL)
	{
		if (ft_strequal(((t_dict *)node->content)->key, key) == TRUE)
			return (ft_del_node(prev_node, node));
		prev_node = node;
		node = node->next;
	}
	return (EXIT_FAILURE);
}
