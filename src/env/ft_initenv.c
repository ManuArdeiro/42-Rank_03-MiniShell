/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:37:26 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/02 21:59:35 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	If an environemnt is passed as argument this function reads it and save 
	every item to the environment list overwriten it if already exists.	*/

static void	ft_get_envlist(t_list **envlist, char **env)
{
	char	**buffer;

	buffer = NULL;
	while (*env != NULL)
	{
		buffer = ft_split(*env, '=');
		if (buffer)
		{
			ft_setenv(&(*envlist), buffer[0], buffer[1], OVERWRITE_VALUE);
			ft_clear_strarray(buffer);
		}
		buffer = NULL;
		++env;
	}
}

/*	If environment is not passed as argument, this function:
	-	Save the root path to the environment item HOME. 
	-	Save the the local path to the environment item PWD.
	-	Save the /usr/bin/env path to the environment item _.
	-	Save the 1 path to the environment item SHLVL.
	
Qué hace el último punto y por qué? 
Qué pasa si no hay local dir o root dir?	*/

static void	ft_default_envlist(t_list **envlist)
{
	char	*rootdir;
	char	*localdir;

	localdir = ft_get_localpath();
	if (localdir != NULL)
	{
		rootdir = ft_get_rootpath(localdir);
		if (rootdir != NULL)
		{
			ft_setenv(&(*envlist), "HOME", rootdir, TRUE);
			ft_setenv(&(*envlist), "PWD", localdir, TRUE);
		}
	}
	ft_setenv(&(*envlist), "_", "/usr/bin/env", TRUE);
	ft_setenv(&(*envlist), "SHLVL", "1", TRUE);
}

/*	This function creates a list where to save the environment:
	- If environment is passed as argument -> ft_get_envList
	- If enviromente is not passed as argument -> ft_default_envList	*/

t_list	*ft_initenv(char **env)
{
	t_list	*envlist;

	envlist = NULL;
	if (*env == NULL)
		ft_default_envlist(&envlist);
	else
		ft_get_envlist(&envlist, env);
	return (envlist);
}
