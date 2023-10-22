/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:33:30 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/22 21:41:06 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	process(int sig_num)
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
	else if (sig == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		g_status = 1;
		prompt();
	}
}

void		sigint_handler(int sig_num)
{
	if ((sig_num == SIGINT || sig_num == SIGQUIT) && g_pid != 0)
		process(sig_num);
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