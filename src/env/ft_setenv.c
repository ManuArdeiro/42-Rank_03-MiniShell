/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:49:32 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/16 18:53:45 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*ft_create_newdict(char *name, char *value)
{
	t_dict	newdict;

	newdict.name = ft_strdup(name);
	newdict.value = ft_strdup(value);
}

static void	ft_add_entry(t_list **envlist, char *name, char *value)
{
	t_list	*newnode;
	newnode = ft_lstnew(&newenv);
	if (!envlist || *envlist == NULL)
		*envlist = newnode;
	else
		ft_lstadd_back(envlist, newnode);
}

void	ft_setenv(t_list **envlist, char *name, char *value, int overwrite)
{
	if (!name || !value || *name == ' ' || ft_strlen(name) == 0)
		return ;
	if (overwrite == FALSE)
	{
		if (ft_check_name_in_dict(*envlist, name) == FALSE)
			ft_add_entry(envlist, name, value);
	}
	else if (overwrite == TRUE)
		ft_add_entry(envlist, name, value);
}
