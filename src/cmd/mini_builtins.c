/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:53:03 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/16 19:49:03 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function prints to screen.	*/

void	ft_print_screen(char *str)
{
	printf("%s\n", str);
}

/*	This function counts the number of strings inside the array char ** passed
	as argument and returns that number.	*/

int	ft_arg_nbr(char **args)
{
	int	size;

	size = 0;
	while (args[size])
		size++;
	return (size);
}

int	ft_builtins(char **args, t_list *envList, t_global *global)
{
	if (!ft_strncmp(args[0], "cd", 3))
		return (ft_mini_cd(args, envList));
	else if (!ft_strncmp(args[0], "echo", 5))
		return (ft_mini_echo(args));
	else if (!ft_strncmp(args[0], "env", 4))
		return (ft_mini_env(envList));
	else if (!ft_strncmp(args[0], "exit", 5))
		return (ft_mini_exit(global, args));
	else if (!ft_strncmp(args[0], "export", 7))
		return (ft_mini_export(envList, args));
	else if (!ft_strncmp(args[0], "pwd", 4))
		return (ft_mini_pwd());
	else if (!ft_strncmp(args[0], "unset", 6))
		return (ft_mini_unset(envList, args));
	return (EXIT_FAILURE);
}