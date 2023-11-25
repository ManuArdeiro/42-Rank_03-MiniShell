/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:49:32 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/25 17:44:51 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function:
	-	If "overwrite" = ADD_VALUE, it checks if a key (environment item name) 
		is included in the environment list:
			* If it is not, it uses ft_add_to_dict() to include it.
			* If it is, it prints an error.
	-	If "overwrite = OVERWRITE_VALUE, it checks if a key (environment item
		name) is included in the environment list:
			* If it is, the function overwrite the key (environment item name) 
			  using the ft_modifydict() function.
			* If it is not, the function uses ft_add_to_dict() to include it."
*/	

void	ft_setenv(t_list **envlist, char *key, char *value, int overwrite)
{
	if (!key || !value || *key == 32 || ft_strlen(key) == 0)
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
