/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:53:59 by jolopez-          #+#    #+#             */
/*   Updated: 2023/11/11 13:06:29 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function prints help for users to use MiniShell.	*/

void	ft_printhelp(void)
{
	printf("\nInstructions to use minishell:\n"
		"1.- Type just (./)minishell to enter it. No arguments admited!\n"
		"2.- Once you get inside type \"exit\" to stop execution.\n\n");
	exit(EXIT_SUCCESS);
}

/*	This function prints welcome message.	*/

void	ft_printwellcome(void)
{
	printf("---------------------------------------------\n"
		"     ___      ___    __      _       		\n"
		"|\\/|  |  |\\ |  |    (_  |_| |_ |  |  		\n"
		"|  | _|_ | \\| _|_   __) | | |_ |_ |_ 		\n"
		"                              				\n"
		"---------------------------------------------\n"
		"\n\nMiniShell from yzaytoun and jolopez- for 42 project.\n"
		"You are very lucky if you are using it, enjoy it!!\n\n");
}

/*	This function prints an error message noticing the function where
	the error happened and a text message to the error output.	*/

void	ft_printerror(const char *function, const char *string)
{
	if (function != NULL)
	{
		ft_putstr_fd("Function: ", STDERR_FILENO);
		ft_putstr_fd(function, STDERR_FILENO);
		ft_putstr_fd("\n Exited from -> ", STDERR_FILENO);
	}
	ft_putstr_fd(string, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	ft_print_commanderror(const char *commandname)
{
	ft_putstr_fd("MiniShell: command not found: ", STDERR_FILENO);
	ft_putstr_fd(commandname, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}
