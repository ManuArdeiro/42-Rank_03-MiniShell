/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:36:53 by jolopez-          #+#    #+#             */
/*   Updated: 2024/02/08 19:41:21 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	ft_check_flag(char *argument)
{
	int		i;
	t_bool	result;

	i = 0;
	result = FALSE;
	if (argument == NULL)
		return (result);
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

static void	ft_print_args(char **args, int arrlen)
{
	int		i;
	int		j;
	t_bool	n_option;

	i = 1;
	j = 1;
	n_option = FALSE;
	while (args[i] != NULL)
	{
		if (ft_check_flag(args[i]) == TRUE && n_option == FALSE)
		{
			n_option = TRUE;
			i++;
			continue ;
		}
		if (j == 1)
			j++;
		else
			ft_putstr_fd(" ", STDOUT_FILENO);
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (i < arrlen)
			i++;
	}
	if (n_option == FALSE)
		write(1, "\n", 1);
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
	int		arrlen;

	if (args == NULL)
		return (EXIT_FAILURE);
	arrlen = ft_strarraylen(args);
	if (arrlen > 1)
		ft_print_args(args, arrlen);
	return (EXIT_SUCCESS);
}
