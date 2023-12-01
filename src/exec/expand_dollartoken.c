/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollartoken.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:35:59 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/01 19:43:02 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_stringvalue(
		char *variable_name, t_list *envlist, int laststatus)
{
	char	*value;

	value = NULL;
	if (variable_name == NULL || variable_name[0] == '\0')
		return (NULL);
	if (*variable_name == '?' && ft_strlen(variable_name) == 1)
		value = ft_itoa(laststatus);
	else if (*variable_name == '?' && ft_strlen(variable_name) > 1)
		value = ft_strjoin_get(ft_itoa(laststatus), variable_name++);
	else
		value = ft_getenv(variable_name, envlist);
	return (value);
}

static void	ft_expand_stringarray(
		char ***stringarray, int laststatus, t_list *envlist)
{
	int	count;

	if (*stringarray == NULL || envlist == NULL)
		return ;
	count = 0;
	while ((*stringarray)[count] != NULL)
	{
		(*stringarray)[count]
			= ft_get_stringvalue((*stringarray)[count], envlist, laststatus);
		count++;
	}
}

static char	*ft_expand_dollarchain(
		const char *fullstring, int laststatus, t_list *envlist)
{
	char	*expandedstring;
	char	**stringarray;

	expandedstring = NULL;
	stringarray = NULL;
	if (fullstring == NULL || envlist == NULL)
		return (NULL);
	stringarray = ft_split(fullstring, '$');
	ft_expand_stringarray(&stringarray, laststatus, envlist);
	expandedstring = ft_concat_strarray(stringarray, 0);
	ft_clear_strarray(stringarray);
	return (expandedstring);
}

static char	*ft_expand_dollar(
		const char *argument, t_list *envlist, int laststatus)
{
	char	*value;
	char	*variable_name;

	value = NULL;
	variable_name = ft_strchr(argument, '$');
	if (variable_name != NULL)
	{
		if (*(variable_name + 1) != '\0')
			return ((char *)argument);
		variable_name++;
		value = ft_get_stringvalue(variable_name, envlist, laststatus);
	}
	return (value);
}

char	*ft_expand_dollartoken(const char *argument, t_global *global)
{
	char	*value;
	int		dollarcount;

	value = NULL;
	if (argument == NULL || (global != NULL && global->envlist == NULL))
		return (NULL);
	dollarcount = ft_chrcount(argument, '$');
	if (dollarcount > 1)
		value
			= ft_expand_dollarchain(
				argument, global->laststatus, global->envlist);
	else if (dollarcount == 1)
		value = ft_expand_dollar(argument, global->envlist, global->laststatus);
	else
		return ((char *)argument);
	if (value == NULL)
		value = ft_strdup("");
	return (value);
}
