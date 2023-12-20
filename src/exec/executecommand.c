/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executecommand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:44:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/20 21:24:38 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_check_commandname(t_command *command)
{
	if (command == NULL)
		return ;
	if (command->name != NULL && command->args != NULL)
	{
		if (ft_strequal(command->name, (char *)command->args->content) == FALSE)
		{
			free(command->name);
			command->name = ft_strdup((char *)command->args->content);
		}
	}
	else if (command->name == NULL && command->args->content != NULL)
		command->name = ft_strdup((char *)command->args->content);
}

static void	ft_check_variables(t_command *command, t_global *global)
{
	if (exit_status == 1)
		global->laststatus = exit_status;
	if (global->devmode == TRUE)
		ft_printcommand(command);
	ft_check_commandname(command);
}

int	ft_executecommand(t_command *command, t_global *global)
{
	pid_t	*pidarray;
	int		pidcount;
	int		laststatus;

	pidarray = NULL;
	if (command == NULL || global == NULL || command->name == NULL
		|| ft_strlen((char *)command->args->content) == 0)
		return (EXITED);
	ft_check_variables(command, global);
	pidcount = ft_create_subprocess(command, &pidarray, global);
	global->pidarray = pidarray;
	global->pidarray = &pidcount;
	ft_signals(global);
	laststatus = ft_wait_subprocess(command, pidarray, pidcount);
	if (exit_status != 0)
		laststatus = exit_status;
	global->laststatus = laststatus;
	if (pidarray != NULL)
		free(pidarray);
	return (laststatus);
}
