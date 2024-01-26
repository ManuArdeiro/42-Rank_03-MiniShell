/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_subshell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:02:14 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/26 18:46:20 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_execute_child(
		t_minitree *root, t_global *global)
{
	int	status;

	status = EXIT_SUCCESS;
	status = ft_executecommand(
			(t_command *)((t_mininode *)root->content)->content, global);
	exit (status);
}

static void	ft_execute(
		t_minitree *root, t_global *global, int *pid)
{
	(*pid) = fork();
	if ((*pid) == 0)
		ft_execute_child(root, global);
	else if (*pid < 0)
		ft_printerror(__func__, "Fork");
}

int	ft_execute_subshell(t_minitree *root, t_global *global)
{
	int		status;
	pid_t	pid;

	status = EXIT_SUCCESS;
	if (root == NULL)
		return (EXITED);
	ft_execute(root, global, &pid);
	ft_wait_process(&pid, &status, FORK, global);
	return (status);
}
