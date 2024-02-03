/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_subprocess.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:50:22 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/03 16:05:39 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_wait_process(
		pid_t *pid, int *laststatus, t_bool processtype, t_global *global)
{
	int		status;
	pid_t	value_waitpid;

	status = EXIT_SUCCESS;
	if (processtype == FORK)
	{
		value_waitpid = waitpid(*pid, &status, EXIT_SUCCESS);
		if (value_waitpid < 0)
		{
			if (kill(*pid, SIGTERM) < 0)
				ft_printerror(__func__, "Kill function");
		}
		*laststatus = ft_evaluate_subprocess(status, global);
	}
	else if (processtype == BUILTIN)
	{
		if (*pid != EXIT_SUCCESS)
			*laststatus = *pid;
	}
}

int	ft_wait_subprocess(
		t_command *command, pid_t *pid, int pidcount, t_global *global)
{
	int	count;
	int	laststatus;

	laststatus = EXIT_SUCCESS;
	if (pidcount == 0)
		return (EXITED);
	count = 0;
	while (count < pidcount)
	{
		if (ft_isbuiltin(command->name) == TRUE)
			ft_wait_process(&pid[count], &laststatus, BUILTIN, global);
		else
			ft_wait_process(&pid[count], &laststatus, FORK, global);
		++count;
	}
	return (laststatus);
}
