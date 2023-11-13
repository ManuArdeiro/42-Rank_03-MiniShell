/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:32:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/11 17:56:54 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_execute_leftnode(
		t_minitree *root, int *pipeline, t_global *global, int *pid)
{
	int	status;

	status = EXIT_SUCCESS;
	*pid = fork();
	if (*pid == 0)
	{
		ft_closefile(&pipeline[0]);
		if (dup2(pipeline[1], STDOUT_FILENO) < 0)
			ft_printerror(__func__, "DUP2");
		ft_closefile(&pipeline[1]);
		status = ft_navigate_and_execute(root->leftchild, global);
		exit(status);
	}
	else if (*pid < 0)
		ft_printerror(__func__, "Fork");
}

static void	ft_execute_rightnode(
		t_minitree *root, int *pipeline, t_global *global)
{
	int	clone;

	clone = dup(STDIN_FILENO);
	ft_closefile(&pipeline[1]);
	if (dup2(pipeline[0], STDIN_FILENO) < 0)
		ft_printerror(__func__, "DUP2");
	ft_closefile(&pipeline[0]);
	global->status = ft_navigate_and_execute(root->rightchild, global);
	if (dup2(clone, STDIN_FILENO) < 0)
		ft_printerror(__func__, "DUP2");
}

int	ft_execute_pipeline(t_minitree *root, t_global *global)
{
	pid_t	pid;
	int		status;
	int		pipeline[2];

	status = EXIT_SUCCESS;
	if (root == NULL)
		return (EXITED);
	if (pipe(pipeline) < 0)
		ft_printerror(__func__, "Pipe");
	ft_execute_leftnode(root, pipeline, global, &pid);
	ft_execute_rightnode(root, pipeline, global);
	if (waitpid(pid, &status, EXIT_SUCCESS) < 0)
		ft_printerror(__func__, "Wait");
	ft_evaluate_subprocess(global->status);
	ft_evaluate_subprocess(status);
	return (status);
}
