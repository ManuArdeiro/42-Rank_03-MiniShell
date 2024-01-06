/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_subprocess.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:51:19 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/06 21:20:07 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_evaluate_subprocess(int status, t_global *global)
{
	int	exitstatus;

	exitstatus = 0;
	if (WIFSIGNALED(status))
	{
		global->laststatus = g_exit_status;
		exitstatus = g_exit_status;
		return (exitstatus);
	}
	else if (WIFEXITED(status))
	{
		exitstatus = WEXITSTATUS(status);
		if (exitstatus != EXIT_SUCCESS)
			return (exitstatus);
	}
	return (EXIT_SUCCESS);
}
