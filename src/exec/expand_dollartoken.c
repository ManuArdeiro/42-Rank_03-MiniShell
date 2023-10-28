/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollartoken.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:35:59 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/24 20:57:09 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_expand_dollartoken(
		const char *argument, t_list *envlist, int laststatus)
{
	char	*variable_name;
	char	*value;

	variable_name = NULL;
	value = NULL;
	if (argument == NULL || envlist == NULL)
		return (NULL);
	variable_name = ft_strchr(argument, '$');
	if (variable_name != NULL)
	{
		variable_name++;
		if (*variable_name == '?' && *(variable_name + 1) == '\0')
			value = ft_itoa(laststatus);
		else
			value = ft_getenv(variable_name, envlist);
	}
	return (value);
}
