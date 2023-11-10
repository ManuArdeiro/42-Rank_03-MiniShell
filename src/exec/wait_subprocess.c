/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_subprocess.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:50:22 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/04 18:07:15 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_wait_process(pid_t *pid, int *laststatus, t_bool processtype)
{
	int	status;

	status = EXIT_SUCCESS;
	if (processtype == FORK)
	{
		if (waitpid(*pid, &status, EXIT_SUCCESS) < 0)
			ft_printerror(__func__, "Wait process");
		*laststatus = ft_evaluate_subprocess(status);
	}
	else if (processtype == BUILTIN)
	{
		if (*pid != EXIT_SUCCESS)
			*laststatus = *pid;
	}
}

int	ft_wait_subprocess(t_command *command, pid_t *pid, int pidcount)
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
			ft_wait_process(&pid[count], &laststatus, BUILTIN);
		else
			ft_wait_process(&pid[count], &laststatus, FORK);
		++count;
	}
	return (laststatus);
}
