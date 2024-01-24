/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:53:03 by jolopez-          #+#    #+#             */
/*   Updated: 2024/01/24 18:52:44 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function just prints the "not found" error message.	*/

int	ft_print_not_found(char *arg)
{
	ft_putstr_fd("export: ", STDERR_FILENO);
	ft_putstr_fd(arg + 1, STDERR_FILENO);
	ft_putendl_fd(" not found.", STDERR_FILENO);
	return (EXIT_FAILURE);
}

/*	This function just prints the "not a valid identifier" error message.	*/

int	ft_print_not_valid(char *arg)
{
	ft_putstr_fd("export: '", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd("' : not a valid identifier", STDERR_FILENO);
	return (EXIT_FAILURE);
}

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
	if (args == NULL || *args == NULL)
		return (0);
	while (args[size])
		size++;
	return (size);
}

int	ft_builtins(char **args, t_list *envlist, t_global *global)
{
	if (args[0] == NULL)
		return (EXIT_FAILURE);
	if (ft_strequal(args[0], "cd") == TRUE)
		return (ft_mini_cd(args, envlist));
	else if (ft_strequal(args[0], "echo") == TRUE)
		return (ft_mini_echo(args));
	else if (ft_strequal(args[0], "env") == TRUE)
		return (ft_mini_env(envlist, args));
	else if (ft_strequal(args[0], "exit") == TRUE)
		return (ft_mini_exit(global, args));
	else if (ft_strequal(args[0], "export") == TRUE)
		return (ft_mini_export(envlist, args));
	else if (ft_strequal(args[0], "pwd") == TRUE)
		return (ft_mini_pwd());
	else if (ft_strequal(args[0], "unset") == TRUE)
		return (ft_mini_unset(envlist, args));
	else if (ft_strequal(args[0], "clear") == TRUE)
		return (ft_clearscreen(envlist));
	return (EXIT_FAILURE);
}
