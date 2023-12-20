/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:33:30 by jolopez-          #+#    #+#             */
/*   Updated: 2023/12/20 20:48:25 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_sigint(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
	rl_replace_line("", 1);
	if (g_signals.in_heredoc == TRUE)
	{
		rl_on_new_line();
		g_signals.exit_status = 1;
		exit(EXIT_FAILURE);
	}
	else if (g_signals.pidarray == NULL)
	{
		g_signals.exit_status = 1;
		rl_on_new_line();
		rl_redisplay();
	}
	else
		g_signals.exit_status = 130;
	g_signals.sig_exit_status = 1;
}

static void	handle_sigquit(int signum)
{
	int		i;
	char	*nbr;

	i = 0;
	nbr = ft_itoa(signum);
	ft_putstr_fd("Quit: ", STDERR_FILENO);
	ft_putendl_fd(nbr, STDERR_FILENO);
	rl_replace_line("", 1);
	rl_on_new_line();
	while (i < g_signals.pidcount)
	{
		kill(g_signals.pidarray[i], SIGINT);
		i++;
	}
	g_signals.exit_status = 131;
	g_signals.sig_exit_status = 1;
}

void	ft_signals(void)
{
	g_signals.sig_exit_status = 0;
	signal(SIGINT, handle_sigint);
	if (g_signals.pidarray == NULL)
		signal(SIGQUIT, SIG_IGN);
	else
		signal(SIGQUIT, handle_sigquit);
	signal(SIGCHLD, handle_sigquit);
}

