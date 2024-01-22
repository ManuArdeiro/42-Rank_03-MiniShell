/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:05:20 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/18 20:17:31 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function tries to change the cwd to the path dir passed as argument.
	-	If it is not possible, an error message is sent to the standard error
		output.
	-	If it works and the previous directory is saved as OLDPWD in the
		envList.	*/

static char	*ft_get_previousdir(void)
{
	char	*localpath;
	int		lastpos;
	char	*previousdir;

	previousdir = NULL;
	localpath = ft_get_localpath();
	lastpos = ft_chrcount(localpath, '/');
	previousdir = ft_strchr_pos(localpath, '/', lastpos);
	previousdir = ft_cutstr(localpath, previousdir);
	if (ft_strlen(previousdir) == 0)
	{
		if (previousdir != NULL)
			free(previousdir);
		previousdir = ft_strdup("/");
	}
	return (previousdir);
}

static int	ft_save_directory(t_list *envlist, char *oldpwd)
{
	char	*newpwd;

	newpwd = NULL;
	newpwd = getcwd(NULL, 0);
	if (newpwd == NULL)
	{
		ft_putendl_fd("No such file or directory", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	ft_setenv(&envlist, "PWD", newpwd, OVERWRITE_VALUE);
	ft_setenv(&envlist, "OLDPWD", oldpwd, OVERWRITE_VALUE);
	if (newpwd != NULL)
		free(newpwd);
	return (EXIT_SUCCESS);
}

static int	ft_new_folder(t_list *envlist, char *dir)
{
	char	*oldpwd;

	oldpwd = NULL;
	if (dir == NULL)
		return (EXIT_FAILURE);
	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
	{
		ft_putendl_fd("Error. Back to root directory.", STDERR_FILENO);
		ft_setenv(&envlist, "PWD", "/", OVERWRITE_VALUE);
		dir = "/";
		return (chdir(dir));
	}
	if (chdir(dir) != 0)
	{
		ft_putendl_fd("No such file or directory", STDERR_FILENO);
		free (oldpwd);
		return (EXIT_FAILURE);
	}
	else
		ft_save_directory(envlist, oldpwd);
	if (oldpwd != NULL)
		free(oldpwd);
	free(dir);
	return (EXIT_SUCCESS);
}

static int	ft_return_newfolder(char *dir, t_list *envlist)
{
	if (dir == NULL)
		return (EXIT_FAILURE);
	if (ft_strequal("-", dir) == TRUE)
		return (ft_new_folder(envlist, ft_getenv("OLDPWD", envlist)));
	else if (ft_strequal("~", dir) == TRUE)
		return (ft_new_folder(envlist, ft_getenv("HOME", envlist)));
	else if (ft_strequal("..", dir) == TRUE)
		return (ft_new_folder(envlist, ft_get_previousdir()));
	else
		return (ft_new_folder(envlist, dir));
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

int	ft_mini_cd(char **arg, t_list *envlist)
{
	char	*dir;

	if (ft_arg_nbr(arg) > 3)
	{
		ft_print_screen("cd: Too many arguments.");
		return (EXIT_SUCCESS);
	}
	else if (ft_arg_nbr(arg) == 1)
	{
		dir = ft_getenv("HOME", envlist);
		if (dir == NULL)
		{
			ft_print_screen("cd: HOME directory not valid.");
			return (EXIT_FAILURE);
		}
		return (ft_new_folder(envlist, dir));
	}
	dir = ft_strdup(arg[1]);
	return (ft_return_newfolder(dir, envlist));
	return (EXIT_SUCCESS);
}
