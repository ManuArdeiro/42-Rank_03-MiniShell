/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:33:30 by jolopez-          #+#    #+#             */
/*   Updated: 2023/12/20 21:14:57 by jolopez-         ###   ########.fr       */
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
	exit_status = 130;
}

static void	handle_sigquit(int signum)
{
	char	*nbr;

	nbr = ft_itoa(signum);
	ft_putstr_fd("Quit: ", STDERR_FILENO);
	ft_putendl_fd(nbr, STDERR_FILENO);
	rl_replace_line("", 1);
	rl_on_new_line();
	exit_status = 131;
	free(nbr)
}


void	ft_signals(t_global *global)
{
	int	i;

	i = 0;
	signal(SIGCHLD, handle_sigquit);
	signal(SIGINT, handle_sigint);
	if (global->pidarray == NULL)
		signal(SIGQUIT, SIG_IGN);
	else
	{
		signal(SIGQUIT, handle_sigquit);
		while (i < global->pidcount)
		{
			kill(global->pidarray[i], SIGKILL);
			i++;
		}
	}
}
