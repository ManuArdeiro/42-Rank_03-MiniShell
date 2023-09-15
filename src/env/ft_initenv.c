/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:37:26 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/15 19:51:24 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*ft_get_envlist(char **env)
{
	t_list	*envlist;
	char	**buffer;

	buffer = NULL;
	while (*env != NULL)
	{
		buffer = ft_split(*env, "=");
		ft_setenv(&envlist, buffer[0], buffer[1], TRUE);
		ft_clear_strarray(buffer);
		buffer = NULL;
		++env;
	}
	return (envlist);
}

static t_list	*ft_default_envlist(void)
{
	t_list	*envlist;
	char	*rootdir;
	char	*localdir;

	localdir = ft_get_localpath();
	if (localdir != NULL)
	{
		rootdir = ft_strchr_pos(localdir, "/", 2);
		ft_setenv(&envlist, "HOME", rootdir, TRUE);
		ft_setenv(&envlist, "PWD", localdir, TRUE);
	}
	ft_setenv(&envlist, "_", "/usr/bin/env", TRUE);
	ft_setenv(&envlist, "SHLVL", "1", TRUE);
	return (envlist);
}

t_list	*ft_initenv(char **env)
{
	t_list	*envlist;

	if (*env == NULL)
		envlist = ft_default_envlist();
	else
		envlist = ft_get_envlist(env);
	return (envlist);
}
