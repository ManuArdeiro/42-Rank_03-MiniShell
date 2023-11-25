/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:43:48 by jolopez-          #+#    #+#             */
/*   Updated: 2023/11/25 10:46:58 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_set_variable(char *arg, char *name, char *value)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while ((char)arg[j] != '=')
	{
		name[j] = arg[j];
		j++;
	}
	name[j] = '\0';
	j++;
	while (arg[j])
	{
		value[k] = arg[j];
		k++;
		j++;
	}
	value[k] = '\0';
	return ;
}

/*	This function manages the case where the arg is like "name=??"; the actions
	are different depending on the ?? is some character or just '\0'.	*/
	
static void	ft_name_equal(t_list *envList, char **args, int *i)
{
	char	*name;
	char	*value;

	name = malloc(sizeof(char) * (ft_strlen(args[*i])
		- ft_strlen(ft_strchr_pos(args[*i], '=', 0))) + 1);
	value = malloc(sizeof(char)
		* ft_strlen(ft_strchr_pos(args[*i], '=', 0)));
	if (!name || !value)
		return ;
	ft_set_variable(args[*i], name, value);
	ft_setenv(&envList, name, value, ADD_VALUE);
	free (name);
	free (value);
}

/*	This function just prints the "not found" error message.	*/

static int	ft_print_not_found(char **args, int i)
{
	ft_putstr_fd("export: ", STDERR_FILENO);
	ft_putstr_fd(args[i] + 1, STDERR_FILENO);
	ft_putendl_fd(" not found.", STDERR_FILENO);
	return (EXIT_SUCCESS);
}

/*	This function depends on the arguments:
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

int	ft_mini_export(t_list *envList, char **args)
{
	int	i;

	i = 0;
	if (!args || !args[1])
		ft_mini_env(envList);
	while (args[++i])
	{
		if (!ft_strncmp(args[i], "=", 1))
		{
			ft_putendl_fd("export: bad assigment.", STDERR_FILENO);
			return (EXIT_SUCCESS);
		}
		else if (ft_strchr(args[i], '=') != NULL && args[i][0] != '=')
			ft_name_equal(envList, args, &i);
		else if (ft_strchr(args[i], '=') != NULL && args[i][0] == '=')
			return (ft_print_not_found(args, i));
		else if (ft_strchr(args[i], '=') == NULL)
		{
			if (ft_getenv(args[i], envList))
				return (EXIT_SUCCESS);
			else if (!ft_getenv(args[i], envList))
				ft_setenv(&envList, args[i], "\0", OVERWRITE_VALUE);
		}
	}
	return (EXIT_SUCCESS);
}
