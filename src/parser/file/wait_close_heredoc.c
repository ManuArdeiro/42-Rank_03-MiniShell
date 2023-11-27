/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_close_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:27:11 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/27 19:57:32 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_wait_close_heredoc(pid_t child, t_file *file, int *herepipe)
{
	int		status;

	status = EXIT_SUCCESS;
	file->fd = dup(herepipe[0]);
	ft_closepipe(&herepipe[0], &herepipe[1]);
	if (waitpid(child, &status, EXIT_SUCCESS) < 0)
		ft_printerror(__func__, "Wait");
	ft_signals();
	if (g_signals.sig_exit_status != 0)
		kill(child, SIGKILL);
	ft_evaluate_subprocess(status);
}
