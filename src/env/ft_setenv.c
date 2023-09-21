/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:49:32 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/21 19:41:14 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_setenv(t_list **envlist, char *key, char *value, int overwrite)
{
	if (!key || !value || *key == 32
		|| ft_strlen(key) == 0)
		return ;
	if (overwrite == ADD_VALUE)
	{
		if (ft_searchdict(*envlist, key) == FALSE)
			ft_add_to_dict(envlist, key, value);
		else
			ft_printerror(NULL, "Name exits, use overwrite to add");
	}
	else if (overwrite == OVERWRITE_VALUE)
	{
		if (ft_searchdict(*envlist, key) == TRUE)
			ft_modifydict(envlist, key, value);
		else
			ft_add_to_dict(envlist, key, value);
	}
}
