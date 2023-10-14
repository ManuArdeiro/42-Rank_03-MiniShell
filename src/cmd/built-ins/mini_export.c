/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:43:48 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/14 19:59:00 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*	This function manages the case where the arg is like "name=??"; the actions
	are different depending on the ?? is some character or just '\0'.	*/

static void	ft_name_equal(t_list *envList, char **args, int *i)
{
	int		j;
	char	*name;
	char	*value;

	j = 0;
	while (args[*i][j] != "=")
	{
		name = ft_strjoin(name, args[*i][j]);
		j++;
	}
	j++;
	if (args[*i][j])
	{
		while (args[*i][j])
		{
			value = ft_strjoin(value, args[*i][j]);
			j++;
		}
		ft_setenv(envList, name, value, ADD_VALUE);
	}
	else if (!args[*i][j])
	{
		if (!ft_getenv(args[*i], envList))
			ft_setenv(envList, args[*i], '\0', ADD_VALUE);
	}
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

int	ft_export(t_list *envList, char **args)
{
	int	i;

	i = 0;
	if (!args)
		ft_printenv(envList);
	while (args[i])
	{
		if (ft_strncmp(args[i], "=", 2))
		{
			ft_putendl_fd("export: bad assigment.", STDERR_FILENO);
			return (EXIT_SUCCESS);
		}
		else if (ft_strchr(args[i], "=") != NULL && args[i][0] != "=")
			ft_name_equal(envList, args, &i);
		else if (ft_strchr(args[i], "=") != NULL && args[i][0] == "=")
			return (ft_print_not_found(args, i));
		else if (ft_strchr(args[i], "=") == NULL)
		{
			if (ft_getenv(args[i], envList))
				return (EXIT_SUCCESS);
			else if (!ft_getenv(args[i], envList))
				ft_setenv(envList, args[i], '\0', ADD_VALUE);
		}
	}
	return (EXIT_SUCCESS);
}
