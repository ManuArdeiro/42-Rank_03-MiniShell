/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:33:30 by jolopez-          #+#    #+#             */
/*   Updated: 2023/12/22 20:54:02 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_sigint_exit(int signum)
{
	(void)signum;
	g_exit_status = 130;
	exit(EXIT_FAILURE);
}

//static void	handle_sigint(int signum)
//{
//	(void)signum;
//	write(1, "\n", 1);
//	rl_replace_line("", 1);
//	rl_on_new_line();
//	rl_redisplay();
//	g_exit_status = 130;
//}

static void	handle_sigquit(int signum)
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

void	ft_signals(t_global *global)
{
	int	i;

	i = 0;
	if (global->in_heredoc == TRUE)
		signal(SIGINT, handle_sigint_exit);
	else
		signal(SIGINT, SIG_IGN);
	if (global->pidarray != NULL)
	{
		signal(SIGQUIT, handle_sigquit);
		while (i < global->pidcount)
		{
			kill(global->pidarray[i], SIGKILL);
			i++;
		}
	}
}
