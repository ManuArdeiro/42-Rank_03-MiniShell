/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executecommand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:44:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/26 19:44:47 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_executecommand(t_command *command, t_global *global)
{
	pid_t	*pidarray;
	int		pidcount;
	int		laststatus;

	pidarray = NULL;
	laststatus = EXIT_SUCCESS;
	if (command == NULL || global == NULL)
		return (EXIT_FAILURE);
	if (global->devmode == TRUE)
		ft_printcommand(command);
	pidcount = ft_create_subprocess(command, &pidarray, global);
	laststatus = ft_wait_subprocess(command, pidarray, pidcount, global);
	if (pidarray != NULL)
		free(pidarray);
	return (laststatus);
}
