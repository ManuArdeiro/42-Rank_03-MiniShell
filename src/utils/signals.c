/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:33:30 by jolopez-          #+#    #+#             */
/*   Updated: 2023/12/23 16:19:11 by yzaytoun         ###   ########.fr       */
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

void	handle_sigint(int signum)
{
	(void)signum;
	write(1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
	g_exit_status = 130;
}

void	handle_sigquit(int signum)
{
	char	*nbr;

	nbr = ft_itoa(signum);
	printf("sigquwitesf\n");
	ft_putstr_fd("Quit: ", STDERR_FILENO);
	ft_putendl_fd(nbr, STDERR_FILENO);
	rl_replace_line("", 1);
	rl_on_new_line();
	free(nbr);
	g_exit_status = 131;
}

static void	ft_switch_sigint(t_global *global)
{
	if (global->in_heredoc == TRUE)
	{
		if (signal(SIGINT, handle_sigint_exit) == SIG_ERR)
			ft_printerror(__func__, "SigINT");
	}
	else if (global->in_heredoc == HEREDOC_EXE)
	{
		if (signal(SIGINT, SIG_IGN) == SIG_ERR)
			ft_printerror(__func__, "SigINT");
		global->in_heredoc = FALSE;
	}
	else if (global->in_heredoc == FALSE)
		if (signal(SIGINT, handle_sigint) == SIG_ERR)
			ft_printerror(__func__, "SigINT");
}

void	ft_signals(t_global *global)
{
	int	i;

	i = 0;
	if (global == NULL)
		return ;
	ft_switch_sigint(global);
}
