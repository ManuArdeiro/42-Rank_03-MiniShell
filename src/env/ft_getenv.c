/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:49:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/13 18:50:36 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_name(t_dict *envlist, const char *name)
{
	t_dict	*node;

	node = envlist;
	while (node != NULL)
	{
		if (ft_strcmp(node->name, name) == 0)
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}

void	ft_setenv(t_dict **envlist, char *name, char *value, int overwrite)
{
	t_list	*newnode;
	t_dict	newenv;

	if (envlist == NULL || !name || !value)
		return ;
	if (ft_check_nam(envlist, name) == FALSE)
	{
		newenv.name = name;
		newenv.value = value;
		newnode = ft_lstnew((void *)newenv);
		ft_lstadd_back(envlist, newnode);
	}
}

char	*ft_getenv(t_dict *envlist, const char *name)
{
	t_dict	*node;

	node = envlist;
	while (node != NULL)
	{
		if (ft_strcmp(node->name, name) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}