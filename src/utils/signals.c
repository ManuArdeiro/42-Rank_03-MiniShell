/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:33:30 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/25 20:04:26 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_process(int sig_num)
{
	if (!kill(g_pid, sig_num))
	{
		if (sig_num == SIGQUIT)
		{
			ft_putstr_fd("Quit: 3\n", 1);
			g_status = 131;
		}
		else if (sig_num == SIGINT)
		{
			ft_putchar_fd('\n', 1);
			g_status = 130;
		}
	}
	else if (sig_num == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		g_status = 1;
		prompt();
	}
}

void	ft_sigint_handler(int sig_num)
{
	if ((sig_num == SIGINT || sig_num == SIGQUIT) && g_pid != 0)
		ft_process(sig_num);
	else
	{
		if (sig_num == SIGINT)
		{
			ft_putchar_fd('\n', 1);
			g_status = 1;
			prompt();
		}
		else if (sig_num == SIGQUIT)
			ft_putstr_fd("\b\b  \b\b", 1);
	}
}



















/**/

void	ft_signal(t_sig_func function, int flag)
{
	signal(SIGINT, function);
	if (flag == 0)
		signal(SIGQUIT, function);
	else
		signal(SIGQUIT, SIG_IGN);
}

void	sig_handler_wait(int sig_num)
{
	(void) sig_num;
	write(1, "\n", 1);
}

void	sig_handler_interactive(int sig_num)
{
	if (sig_num == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
		g_exit_status = ST_SIGINT;
	}
}

void	sig_handler_here_doc(int sig_num)
{
	if (sig_num == SIGINT)
	{
		ioctl(0, TIOCSTI, "\n");
		rl_on_new_line();
		g_exit_status = ST_SIGINT_HEREDOC;
	}
}