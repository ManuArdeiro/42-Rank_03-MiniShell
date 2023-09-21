/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:37:26 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/21 20:46:54 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

t_list	*ft_initenv(char **env)
{
	t_list	*envlist;

	envlist = NULL;
	if (*env == NULL)
		ft_default_envlist(&envlist);
	else
		ft_get_envlist(&envlist, env);
	//ft_printenv(envlist);
	return (envlist);
}
