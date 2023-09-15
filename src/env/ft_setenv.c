/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:49:32 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/15 19:36:55 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_setenv(t_list **envlist, char *name, char *value, int overwrite)
{
	t_list	*newnode;
	t_dict	newenv;

	if (!name || !value || *name == " " || ft_strlen(name) == 0)
		return ;
	if (overwrite == FALSE)
	{
		if (ft_check_name_in_dict(envlist, name) == FALSE)
		{
			newenv.name = ft_strdup(name);
			newenv.value = ft_strdup(value);
			newnode = ft_lstnew(&newenv);
			ft_lstadd_back(envlist, newnode);
		}
	}
	else if (overwrite == TRUE)
	{
		newenv.name = ft_strdup(name);
		newenv.value = ft_strdup(value);
		newnode = ft_lstnew(&newenv);
		ft_lstadd_back(envlist, newnode);
	}
}