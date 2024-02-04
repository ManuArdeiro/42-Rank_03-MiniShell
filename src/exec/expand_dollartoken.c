/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollartoken.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:35:59 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/04 16:20:23 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_limiter(const char *string)
{
	int		i;

	i = 0;
	if (string == NULL)
		return (NULL);
	while (string[i] != '\0')
	{
		if (ft_isalnum(string[i]) == FALSE)
			return ((char *)string + i);
		i++;
	}
	return (NULL);
}

static char	*ft_get_stringvalue(
		char *variable_name, t_list *envlist, int laststatus)
{
	char	*value;
	char	*limiter;
	char	*stringprefix;

	value = NULL;
	limiter = ft_get_limiter(variable_name);
	stringprefix = ft_cutstr(variable_name, limiter);
	if (variable_name == NULL || variable_name[0] == '\0')
		return (NULL);
	else if (*variable_name == '?')
		value = ft_strjoin_get(ft_itoa(laststatus), variable_name + 1);
	else if (limiter != NULL)
		value = ft_strjoin_get(ft_getenv(stringprefix, envlist), limiter);
	else
		value = ft_getenv(variable_name, envlist);
	if (stringprefix != NULL)
		free(stringprefix);
	if (value == NULL)
		value = ft_strdup("");
	return (value);
}

static void	ft_expand_stringarray(
		char **stringarray, int laststatus, t_global *global)
{
	int		count;
	char	*buffer;

	buffer = NULL;
	if (*stringarray == NULL || global->envlist == NULL)
		return ;
	if (global->stringstart == TRUE)
		count = 1;
	else
		count = 0;
	while (stringarray[count] != NULL)
	{
		buffer = ft_get_stringvalue(
				stringarray[count], global->envlist, laststatus);
		if (buffer != NULL)
		{
			free(stringarray[count]);
			stringarray[count] = buffer;
		}
		count++;
	}
}

static char	*ft_expand_dollarchain(
	const char *fullstring, int laststatus, t_global *global)
{
	char	*expandedstring;
	char	**stringarray;
	t_list	*list;

	expandedstring = NULL;
	stringarray = NULL;
	list = NULL;
	if (fullstring == NULL || global->envlist == NULL)
		return (NULL);
	list = ft_get_stringlist(fullstring, global);
	stringarray = ft_lstconvert_strarr(list, 0);
	ft_expand_stringarray(stringarray, laststatus, global);
	expandedstring = ft_concat_strarray(stringarray, FALSE);
	ft_clear_strarray(stringarray);
	ft_lstclear(&list, ft_free_string);
	global->stringstart = FALSE;
	return (expandedstring);
}

char	*ft_expand_dollartoken(const char *argument, t_global *global)
{
	char	*value;
	int		dollarcount;

	value = NULL;
	global->expand_dollartoken = FALSE;
	if (argument == NULL || (global != NULL && global->envlist == NULL))
		return (NULL);
	dollarcount = ft_chrcount(argument, '$');
	if (dollarcount >= 1)
	{
		value
			= ft_expand_dollarchain(
				argument, g_exit_status, global);
		if (value == NULL)
			value = ft_strdup("");
	}
	else
		return ((char *)argument);
	return (value);
}
