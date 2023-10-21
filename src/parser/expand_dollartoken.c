/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollartoken.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:35:59 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/21 12:55:47 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_expand_dollartoken(const char *argument, t_list *envlist)
{
	char	*variable_name;
	char	*value;

	if (argument == NULL || envlist == NULL)
		return (NULL);
	value = NULL;
	variable_name = ft_strchr(argument, '$');
	if (variable_name != NULL)
	{
		variable_name++;
		value = ft_getenv(variable_name, envlist);
	}
	return (value);
}
