/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:33:30 by jolopez-          #+#    #+#             */
/*   Updated: 2024/01/04 18:53:08 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigint_exit(int signum)
{
	(void)signum;
	write(1, "\n", 1);
	g_exit_status = 130;
	exit(130);
}

void	handle_sigint2(int signum)
{
	(void)signum;
	write(1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	g_exit_status = 130;
}

void	handle_sigquit(int signum)
{
	char	*nbr;

	nbr = ft_itoa(signum);
	ft_putstr_fd("Quit: ", STDERR_FILENO);
	ft_putendl_fd(nbr, STDERR_FILENO);
	rl_replace_line("", 1);
	rl_on_new_line();
	free(nbr);
	g_exit_status = 131;
}

void	ft_signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
		g_exit_status = 130;
	}
	else if (signum == SIGQUIT)
		handle_sigquit(signum);
	else if (signum == SIGHUP || signum == SIGTSTP || signum == SIGTERM)
		exit(130);
}


void	ft_initsignals(t_global *global)
{
	t_sigaction	signallist;
	sigset_t	blockmask;

	if (global == NULL)
		return ;
	sigemptyset(&blockmask);
	sigaddset(&blockmask, SIGINT);
	sigaddset(&blockmask, SIGQUIT);
	signallist.sa_mask = blockmask;
	signallist.sa_flags = SA_RESTART;
	signallist.sa_handler = &ft_signal_handler;
	sigaction(SIGINT, &signallist, NULL);
	signallist.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &signallist, NULL);
	global->signallist = signallist;
}
