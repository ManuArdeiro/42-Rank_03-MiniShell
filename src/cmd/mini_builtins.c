/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:53:03 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/14 20:02:41 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
	
}