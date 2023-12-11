/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executecommand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:44:36 by yzaytoun          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/12/11 20:11:43 by jolopez-         ###   ########.fr       */
=======
/*   Updated: 2023/12/11 19:51:19 by yzaytoun         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_check_commandname(t_command *command)
{
	if (command == NULL)
		return ;
	if (command->name != NULL
		&& ft_strequal(command->name, (char *)command->args->content) == FALSE)
	{
		free(command->name);
		command->name = ft_strdup((char *)command->args->content);
	}
	else if (command->name == NULL && command->args->content != NULL)
		command->name = ft_strdup((char *)command->args->content);
}

int	ft_executecommand(t_command *command, t_global *global)
{
	pid_t	*pidarray;
	int		pidcount;
	int		laststatus;

	pidarray = NULL;
	if (command == NULL || global == NULL || command->name == NULL)
		return (EXITED);
	if (g_signals.sig_exit_status == 1)
		global->laststatus = g_signals.exit_status;
	g_signals.sig_exit_status = 0;
	//ft_printcommand(command);
	ft_check_commandname(command);
	pidcount = ft_create_subprocess(command, &pidarray, global);
	g_signals.pidarray = pidarray;
	g_signals.pidcount = pidcount;
	ft_signals();
	laststatus = ft_wait_subprocess(command, pidarray, pidcount);
	if (g_signals.sig_exit_status != 0)
		laststatus = g_signals.exit_status;
	global->laststatus = laststatus;
	if (pidarray != NULL)
		free(pidarray);
	g_signals.pidarray = NULL;
	return (laststatus);
}
