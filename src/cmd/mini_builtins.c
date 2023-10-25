/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:53:03 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/24 20:27:00 by yzaytoun         ###   ########.fr       */
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
	printf("HERE222\n");
	if (ft_strequal(args[0], "cd") == TRUE)
		return (ft_mini_cd(args, envList));
	else if (ft_strequal(args[0], "echo") == TRUE)
		return (ft_mini_echo(args));
	else if (ft_strequal(args[0], "env") == TRUE)
		return (ft_mini_env(envList));
	else if (ft_strequal(args[0], "exit") == TRUE)
		return (ft_mini_exit(global, args));
	else if (ft_strequal(args[0], "export") == TRUE)
		return (ft_mini_export(envList, args));
	else if (ft_strequal(args[0], "pwd") == TRUE)
		return (ft_mini_pwd());
	else if (ft_strequal(args[0], "unset") == TRUE)
		return (ft_mini_unset(envList, args));
	return (EXIT_FAILURE);
}