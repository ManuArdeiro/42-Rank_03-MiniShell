/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:33:30 by jolopez-          #+#    #+#             */
/*   Updated: 2023/11/04 16:51:39 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sig_int(int sig_num)
{
	(void)sig_num;
	if (g_signals.pid == 0)
	{
		ft_putchar_fd('\n', 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
		g_signals.exit_status = 1;
	}
	else
	{
		ft_putstr_fd("\n", STDERR_FILENO);
		g_signals.exit_status = 130;
	}
	g_signals.sig_int = 1;
}

void	ft_sig_quit(int sig_num)
{
	char	*nbr;

	nbr = ft_itoa(sig_num);
	if (g_signals.pid != 0)
	{
		ft_putstr_fd("Quit: ", STDERR_FILENO);
		ft_putendl_fd(nbr, STDERR_FILENO);
		g_signals.exit_status = 131;
		g_signals.sig_quit = 1;
	}
	else
		ft_putstr_fd("\b\b  \b\b", STDERR_FILENO);
	free(nbr);
}

void	ft_signals(void)
{
	g_signals.sig_int = 0;
	g_signals.sig_quit = 0;
	g_signals.exit_status = 0;
	g_signals.pid = 0;
	signal(SIGINT, &ft_sig_int);
	signal(SIGQUIT, &ft_sig_quit);
}

/* poner en ejecución:

	if (g_sig.sigint == 1 || g_sig.sigquit == 1)
		return (g_signals.exit_status);
		
*/
