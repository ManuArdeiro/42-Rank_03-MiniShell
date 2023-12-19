/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:03:19 by jolopez-          #+#    #+#             */
/*   Updated: 2023/12/19 17:33:24 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function gets the current directory via getcwd() function from the
	unistd library, then print it to the standard output. */

int	ft_mini_pwd(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, PATH_MAX))
	{
		ft_putendl_fd(cwd, STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_putendl_fd("No such file or directory any more", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
}
