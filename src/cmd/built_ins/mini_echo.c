/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:36:53 by jolopez-          #+#    #+#             */
/*   Updated: 2024/02/04 19:33:15 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	check_flags(char *argument)
{
	int		i;
	t_bool	result;

	i = 0;
	result = FALSE;
	if (argument == NULL)
		return (FALSE);
	if (argument[i] == '-')
	{
		++i;
		while (argument[i] != '\0')
		{
			if (argument[i] == 'n')
				result = TRUE;
			else
				result = FALSE;
			if (result == FALSE)
				break ;
			++i;
		}
	}
	return (result);
}

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
	int		arrlen;

	i = 1;
	n_option = FALSE;
	if (args == NULL)
		return (EXIT_FAILURE);
	arrlen = ft_strarraylen(args);
	if (arrlen > 1)
	{
		while (args[i])
		{
			if (check_flags(args[i]) == TRUE)
			{
				n_option = TRUE;
				i++;
			}
			if (args[i] != NULL)
				ft_putstr_fd(args[i], STDOUT_FILENO);
			//if (args[i + 1] && args[i][0] != '\0')
			//	write(1, " ", 1);
			if (i < arrlen)
				i++;
		}
		if (n_option == FALSE)
			write(1, "\n", 1);
	}
	return (EXIT_SUCCESS);
}
