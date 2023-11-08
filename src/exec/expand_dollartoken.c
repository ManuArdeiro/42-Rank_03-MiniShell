/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollartoken.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:35:59 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/08 20:28:49 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_stringvalue(
		const char *variable_name, t_list *envlist, int laststatus)
{
	char	*value;

	value = NULL;
	if (variable_name == NULL)
		return (NULL);
	if (*variable_name == '?' && *(variable_name + 1) == '\0')
		value = ft_itoa(laststatus);
	else
		value = ft_getenv(variable_name, envlist);
	return (value);
}


static char	*ft_expand_dollarchain(
		const char *fullstring,
		int dollarcount, int laststatus, t_list *envlist)
{
	t_list	*stringlist;
	char	*stringpart;
	char	*stringvalue;
	int		count;

	count = 0;
	stringlist = NULL;
	if (fullstring == NULL)
		return (NULL);
	stringpart = NULL;
	while (count < dollarcount)
	{
		stringpart = ft_strchr_pos(fullstring, '$', count);
		if (stringpart != NULL)
		{
			stringpart = ft_cutstr(fullstring, stringpart);
			stringvalue = ft_get_stringvalue(stringpart, envlist, laststatus);
			if (stringvalue != NULL)
				ft_lstinsert(&stringlist, stringvalue, BACK);
		}
		count++;
	}
	expandedstring = ft_lstconvert_strarr(stringlist);
	expandedstring = ft_concat_strarray(stringarray, '');
	return (stringlist);
}

char	*ft_expand_dollartoken(
		const char *argument, t_list *envlist, int laststatus)
{
	char	*variable_name;
	char	*value;
	int		dollarcount;

	variable_name = NULL;
	value = NULL;
	if (argument == NULL || envlist == NULL)
		return (NULL);
	dollarcount = ft_chrcount(argument, '$');
	if (dollarcount > 1)
		value
			= ft_expand_dolarchain(argument, dollarcount, laststatus, envlist);
	else
	{
		variable_name = ft_strchr(argument, '$');
		if (variable_name != NULL)
		{
			variable_name++;
			value = ft_get_stringvalue(variable_name, envlist, laststatus);
		}
	}
	return (value);
}
