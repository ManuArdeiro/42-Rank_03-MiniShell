/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:45:47 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/16 19:49:47 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execute_pipeline(t_mininode *mininode, char **envp)
{
	int	fd[2];
	int	count;

	count = 0;
	if (mininode == NULL)
		return (EXITED);
	if (pipe(fd) < 0)
		return (EXITED);
	//ft_get_tokencount
	while (count < pipcount)
	{
		pid = fork();
		if (pid == 0)
			//ft_execute....
		count++;
	}
}
