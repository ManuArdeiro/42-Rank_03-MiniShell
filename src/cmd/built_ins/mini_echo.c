/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:36:53 by jolopez-          #+#    #+#             */
/*   Updated: 2023/12/20 20:34:24 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function check the first argument:
	-	If it is "-n" then all the arguments will be written (separated by
		spaces) to the standard	output but "\n" won't be written at the end 
		of the arguments.
	-	If it is not "-n", then all the arguments will be written (separated 
		by spaces) to the standard output and after them a "\n" will be 
		written.	*/

int	ft_mini_echo(char **args)
{
	int		i;
	t_bool	n_option;

	i = 1;
	n_option = FALSE;
	while (args[i])
	{
		if (ft_strncmp(args[i], "-n", 3) == 0)
		{
			n_option = TRUE;
			i++;
		}
		while (args[i])
		{
			ft_putstr_fd(args[i], STDOUT_FILENO);
			if (args[i + 1] && args[i][0] != '\0')
				write(1, " ", 1);
			i++;
		}
	}
	if (n_option == FALSE)
		write(1, "\n", 1);
	return (EXIT_SUCCESS);
}
