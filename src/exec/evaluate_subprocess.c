/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_subprocess.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:51:19 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/11 20:08:39 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_evaluate_subprocess(int status)
{
	int	exitstatus;

	exitstatus = 0;
	if (WIFEXITED(status))
	{
		exitstatus = WEXITSTATUS(status);
		if (exitstatus != EXIT_SUCCESS)
		{
			//printf("Process Exited with status -> %d \n", exitstatus);
			return (exitstatus);
		}
	}
	return (EXIT_SUCCESS);
}
