/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:33:30 by jolopez-          #+#    #+#             */
/*   Updated: 2023/12/24 18:49:27 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigint_exit(int signum)
{
	(void)signum;
	write(1, "\n", 1);
	write(1, "hola", 4);
	g_exit_status = 130;
	exit(130);
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
}


void	ft_initsignals(t_global *global)
{
	t_sigaction	signallist;

	if (global == NULL)
		return ;
	signallist.__sigaction_u.__sa_handler = &ft_signal_handler;
	sigaction(SIGINT, &signallist, NULL);
	signallist.__sigaction_u.__sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &signallist, NULL);
	global->signallist = signallist;
}
