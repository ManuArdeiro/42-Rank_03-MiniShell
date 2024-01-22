/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:42:21 by jolopez-          #+#    #+#             */
/*   Updated: 2024/01/18 19:42:42 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function deletes the simple/double quots if they are in the string
	passed as argument.	*/

static void	ft_del_quots(char *argument)
{
	int	i;

	i = 0;
	if (!argument)
		return ;
	while (argument[i] != '\0')
	{
		if (argument[i] == '\'' || argument[i] == '\"')
			argument[i] = '0';
		i++;
	}
	return ;
}

/*	This function returs a TRUE if the string passed as argument is a number,
	a FALSE if not. */

static t_bool	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (FALSE);
	if (str[0] != '-' && str[0] != '+' && !ft_isdigit(str[0]))
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
	if (ft_arg_nbr(args) > 2)
	{
		ft_putendl_fd("exit: too many arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	else if (ft_arg_nbr(args) == 2)
	{
		ft_del_quots(args[1]);
		if (!ft_is_number(args[1]))
		{
			ft_putendl_fd("exit: numeric argument required", STDERR_FILENO);
			return (255);
		}
		else
			global->laststatus = ft_atoi(args[1]);
	}
	ft_putendl_fd("exit", STDOUT_FILENO);
	global->status = EXITED;
	return (global->laststatus);
}
