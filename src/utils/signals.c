/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:33:30 by jolopez-          #+#    #+#             */
/*   Updated: 2023/11/04 20:22:50 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_sigint(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
	g_signals.exit_status = 1;
}

static void	handle_sigquit(int signum)
{
	char	*nbr;

	nbr = ft_itoa(signum);
	if (signum != SIGQUIT)
		return ;
	ft_putstr_fd("Quit: ", STDERR_FILENO);
	ft_putendl_fd(nbr, STDERR_FILENO);
	g_signals.exit_status = 131;
	g_signals.sig_quit = 1;
}

void	ft_signals(void)
{
	signal(SIGINT, handle_sigint);
	if (g_signals.pidarray == 0)
		signal(SIGQUIT, SIG_IGN);
	else
		signal(SIGQUIT, handle_sigquit);
}
