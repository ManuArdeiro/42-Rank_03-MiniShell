/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:33:30 by jolopez-          #+#    #+#             */
/*   Updated: 2023/12/24 19:11:56 by Ardeiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_sigchd(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
	exit_status = 1;
}

static void	handle_sigint(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
	exit_status = 130;
}

static void	handle_sigquit(int signum)
{
	char	*nbr;

	if (signum != SIGQUIT)
		return ;
	nbr = ft_itoa(signum);
	ft_putstr_fd("Quit: ", STDERR_FILENO);
	ft_putendl_fd(nbr, STDERR_FILENO);
	rl_replace_line("", 1);
	rl_on_new_line();
	exit_status = 131;
}

void	ft_signals(t_global *global)
{
	global->sig_exit_status = 0;
	if (global->pidarray == NULL)
	{
		signal(SIGINT, handle_sigchd);
		signal(SIGQUIT, SIG_IGN);
		global->sig_exit_status = 1;
	}
	else if (global->in_heredoc == TRUE)
	{
		signal(SIGINT, handle_sigchd);
		signal(SIGQUIT, handle_sigquit);
		global->sig_exit_status = 1;
	}
	else
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, handle_sigquit);
	}
}
