/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:05:20 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/30 20:26:35 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function tries to change the cwd to the path dir passed as argument.
	-	If it is not possible, an error message is sent to the standard error
		output.
	-	If it works and the previous directory is saved as OLDPWD in the
		envList.	*/

static void	ft_save_directory(t_list *envlist, char *oldpwd)
{
	char	*newpwd;

	newpwd = NULL;
	newpwd = getcwd(NULL, 0);
	ft_setenv(&envlist, "PWD", newpwd, OVERWRITE_VALUE);
	ft_setenv(&envlist, "OLDPWD", oldpwd, OVERWRITE_VALUE);
	if (newpwd != NULL)
		free(newpwd);
}

static int	ft_new_folder(t_list *envlist, char *dir)
{
	char	*oldpwd;

	oldpwd = NULL;
	if (dir == NULL)
		return (EXIT_FAILURE);
	oldpwd = getcwd(NULL, 0);
	if (chdir(dir) != 0)
	{
		ft_putstr_fd(dir, STDERR_FILENO);
		ft_putstr_fd(" ", STDERR_FILENO);
		ft_putendl_fd("error", STDERR_FILENO);
		free (oldpwd);
		return (EXIT_FAILURE);
	}
	else
		ft_save_directory(envlist, oldpwd);
	if (oldpwd != NULL)
		free(oldpwd);
	return (EXIT_SUCCESS);
}

/*	This function tries to apply the "cd" commands follwing the next rules:
	-	If arguments > 1 ->	an error is written in the consolo (too many
		arguments).
	-	If arguments = 0 ->	try to change to HOME path stored in envList 
		list.
	-	If arguments = 1 ->	two different cases:
							* If arg = "-" then function tries to change 
							  cwd to OLDPWD value stored in the envList.
							* If arg != "-" then functions tries to change 
							  cwd to path passed as argument.	*/

int	ft_mini_cd(char **arg, t_list *envList)
{
	char	*dir;


	if (ft_arg_nbr(arg) > 3)
	{
		ft_print_screen("cd: Too many arguments.");
		return (EXIT_SUCCESS);
	}
	else if (ft_arg_nbr(arg) == 1)
	{
		dir = ft_getenv("HOME", envList);
		if (dir == NULL)
		{
			ft_print_screen("cd: HOME directory not valid.");
			return (EXIT_FAILURE);
		}
		return (ft_new_folder(envList, dir));
	}
	dir = arg[1];
	if (ft_strncmp("-", dir, 2))
		return (ft_new_folder(envList, ft_getenv("OLDPWD", envList)));
	else
		return (ft_new_folder(envList, dir));
	return (EXIT_SUCCESS);
}
