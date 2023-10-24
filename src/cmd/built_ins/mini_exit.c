/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:42:21 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/24 19:42:27 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function returs a TRUE if the string passed as argument is a number,
	a FALSE if not. */

static t_bool	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (FALSE);
	if (str[0] != '-' && !ft_isdigit(str[0]))
		return (FALSE);
	i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/*	This function exits from the minishell (stopping the loop in main). 
	There are 3 different scenarios:
	-	arguments > 1 -> shows an error message (too many arguments), no exit.
	-	arguments = 1 -> two different cases:
					* arg = valid number -> exits the minishell returning 
											the valid number.
					* arg != valid number -> shows an error, no exit. 
	-	arguments = 0 -> exits the minishell returning EXIT_SUCCESS. */

int	ft_mini_exit(t_global *global, char **args)
{
	ft_putendl_fd("exit", STDOUT_FILENO);
	if (ft_arg_nbr(args) > 2)
	{
		ft_putendl_fd("exit: too many arguments.", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	else if (ft_arg_nbr(args) == 2)
	{
		if (!ft_is_number(args[1]))
		{
			ft_putendl_fd("exit: numeric argument required.", STDERR_FILENO);
			return (1);
		}
		else
		{
			global->status = EXITED;
			return (ft_atoi(args[1]));
		}
	}
	global->status = EXITED;
	return (EXIT_SUCCESS);
}