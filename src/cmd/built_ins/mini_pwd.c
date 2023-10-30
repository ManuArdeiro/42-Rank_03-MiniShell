/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:03:19 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/30 20:10:58 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function gets the current directory via getcwd() function from the
	unistd library, then print it to the standard output. */

int	ft_mini_pwd(t_list *envlist)
{
	char	*cwd;

	//char	cwd[PATH_MAX];
	cwd = NULL;
	//if (getcwd(cwd, PATH_MAX))
	if (envlist == NULL)
		return (EXIT_FAILURE);
	cwd = ft_getenv("PWD", envlist);
	printf("cwd =%s\n", cwd);
	if (cwd != NULL)
	{
		ft_putendl_fd(cwd, STDOUT_FILENO);
		free(cwd);
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}
