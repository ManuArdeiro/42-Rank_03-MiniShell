/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:05:20 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/07 13:34:31 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_new_folder(t_list *envlist, char *dir)
{
	char	*current;

	if (dir == NULL)
		return (1);
	current = getcwd(NULL, 0);
	if (chdir(dir) != 0)
	{
		ft_putstr_fd(dir, 2);
		ft_putstr_fd(" ", 2);
		ft_putendl_fd(strerror(chdir(dir)), 2);
		free (current);
		return (1);
	}
	else
		ft_setenv(envlist, "OLDPWD", current, OVERWRITE_VALUE);
	free(current);
	return (0);
}

int	ft_mini_cd(char **arg, t_list *envlist)
{
	char	*dir;
	
	if (ft_arr_len(arg) > 2)
	{
		ft_print_screen("cd: Too many arguments.");
		return (EXIT_SUCCESS);
	}
	else if (ft_arr_len(arg) == 1)
	{
		dir = ft_getenv("HOME", envlist);	
		if (dir == NULL)
		{
			ft_print_screen("cd: HOME directory not valid.");
			return (EXIT_SUCCESS);		
		}
		return (change_path(envList, dir));
	}
	dir = arg[0];
	if (ft_strncmp("-", dir, 2))
		return (change_path(envList, ft_getenv("OLDPWD", envList)));
	else
		return (change_path(envList, dir));
	return (0);
}
