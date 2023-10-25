/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_subprocess.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:50:22 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/25 18:23:55 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_wait_subprocess(pid_t *pid, int pidcount)
{
	int	count;
	int	status;
	int	laststatus;

	status = EXIT_SUCCESS;
	laststatus = EXIT_SUCCESS;
	if (pidcount == 0)
		return (EXITED);
	count = 0;
	while (count < pidcount)
	{
		if (waitpid(pid[count], &status, EXIT_SUCCESS) < 0)
		{
			laststatus = ft_evaluate_subprocess(status);
			return (laststatus);
		}
		++count;
	}
	return (laststatus);
}
