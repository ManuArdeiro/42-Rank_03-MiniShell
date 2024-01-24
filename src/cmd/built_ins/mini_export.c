/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:43:48 by jolopez-          #+#    #+#             */
/*   Updated: 2024/01/24 18:51:55 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function checks the string passed as argument and returns:
	1 if only numbers in the string
	0 if alphabetical characters in the string	*/

static int	ft_check_name(const char *name)
{
	int	i;

	i = 0;
	if (ft_isdigit(name[i]) == TRUE)
		return (EXIT_FAILURE);
	while (name[i] != '\0')
	{
		if (ft_isalnum(name[i]) != TRUE && name[i] != '_')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

/*	This function splits the arg string in name (the part of arg string
	before the =) and value (the part of arg string after the =). 
	Also checks if name is valid (only alphabetical characters and not 
	only numbers, via ft_check_name function).	*/

static int	ft_set_variable(char *arg, char *name, char *value)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while ((char)arg[j] != '=')
	{
		if (ft_isalnum(arg[j]) != TRUE && arg[j] != '_')
			return (EXIT_FAILURE);
		name[j] = arg[j];
		j++;
	}
	name[j] = '\0';
	if (ft_check_name(name) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	j++;
	while (arg[j])
	{
		value[k] = arg[j];
		k++;
		j++;
	}
	value[k] = '\0';
	return (EXIT_SUCCESS);
}

/*	This function manages the case where the arg is like "name=??"; the actions
	are different depending on the ?? is some character or just '\0'.	*/

static int	ft_name_equal(t_list *envList, char *argument)
{
	char	*name;
	char	*value;

	name = malloc(sizeof(char) * (ft_strlen(argument)
				- ft_strlen(ft_strchr_pos(argument, '=', 0))) + 1);
	value = malloc(sizeof(char)
			* ft_strlen(ft_strchr_pos(argument, '=', 0)));
	if (!name || !value)
		return (EXIT_FAILURE);
	if (ft_set_variable(argument, name, value) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	value = ft_strclean_withspaces(value, CLEAN_QUOTES);
	ft_setenv(&envList, name, value, OVERWRITE_VALUE);
	free (name);
	free (value);
	return (EXIT_SUCCESS);
}

/*	This functions depends on the arguments:
	-	No arguments: - it prints all environment variables (including 
		unnassigned ones).
	-	Arguments: if there are arguments they should be like this: name[=word]
			* First: a name to include the variable in the envList.
			* Second(optional): =
			* Third(optional): value for the name variable.
	When there are arguments, the first one has to be a name (if it is an 
	equal sign, arguments are not correct). Then:
	-	If after the name there is a space (or more), the variable will de 
		added to the envList with value = ' '.
	-	If after the name there is an equal sign then space(s), the variable
		will de added to the envList with value = ' '.
	-	If after the name there is an equalsign then other word, that is the
		value for key = name.	*/

static int	ft_mini_export_aux(t_list *envList, char **args, char *argument,
	int *i)
{
	if (!ft_strncmp(argument, "=", 2))
		return (ft_print_not_valid(args[*i]));
	else if (ft_strchr(argument, '=') != NULL && argument[0] != '=')
	{
		if (ft_name_equal(envList, args[*i]) == 1)
			return (ft_print_not_valid(args[*i]));
	}
	else if (ft_strchr(argument, '=') != NULL && argument[0] == '=')
		return (ft_print_not_found(args[*i]));
	else if (ft_strchr(argument, '=') == NULL)
	{
		if (ft_getenv(argument, envList))
			return (EXIT_SUCCESS);
		else if (!ft_getenv(argument, envList))
		{
			if (ft_check_name(argument) == EXIT_FAILURE)
				return (ft_print_not_valid(args[*i]));
			else
				ft_setenv(&envList, argument, "\0", OVERWRITE_VALUE);
		}
	}
	return (EXIT_SUCCESS);
}

int	ft_mini_export(t_list *envList, char **args)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	if (!args || !args[1])
		ft_mini_env(envList, args);
	while (args[++i])
	{
		result += ft_mini_export_aux(envList, args, args[i], &i);
	}
	if (result != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
