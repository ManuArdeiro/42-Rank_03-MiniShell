/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:32:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/29 18:45:17 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_execute_leftchild(
		t_minitree *root, int *pipeline, t_global *global)
{
	int	status;

	status = EXIT_SUCCESS;
	if (dup2(pipeline[1], STDOUT_FILENO) < 0)
		ft_printerror(__func__, "DUP2");
	ft_closepipe(&pipeline[0], &pipeline[1]);
	status = ft_navigate_and_execute(root->leftchild, global);
	exit (status);
}

static void	ft_execute_rightchild(
		t_minitree *root, int *pipeline, t_global *global)
{
	int	status;

	status = EXIT_SUCCESS;
	if (dup2(pipeline[0], STDIN_FILENO) < 0)
		ft_printerror(__func__, "DUP2");
	ft_closepipe(&pipeline[0], &pipeline[1]);
	status = ft_navigate_and_execute(root->rightchild, global);
	exit (status);
}

static void	ft_execute(
		t_minitree *root, int *pipeline, t_global *global, int **pid)
{
	(*pid)[0] = fork();
	if ((*pid)[0] == 0)
		ft_execute_leftchild(root, pipeline, global);
	else if (*pid < 0)
		ft_printerror(__func__, "Fork");
	(*pid)[1] = fork();
	if ((*pid)[1] == 0)
		ft_execute_rightchild(root, pipeline, global);
	else if (*pid < 0)
		ft_printerror(__func__, "Fork");
}

int	ft_execute_pipeline(t_minitree *root, t_global *global)
{
	int		status;
	int		pipeline[2];
	pid_t	*pid;

	status = EXIT_SUCCESS;
	if (root == NULL)
		return (EXITED);
	pid = malloc(sizeof(pid_t) * (2));
	if (!pid)
		return (EXIT_FAILURE);
	if (pipe(pipeline) < 0)
		ft_printerror(__func__, "Pipe");
	ft_execute(root, pipeline, global, &pid);
	ft_closepipe(&pipeline[0], &pipeline[1]);
	ft_wait_process(&pid[0], &status, FORK, global);
	ft_wait_process(&pid[1], &status, FORK, global);
	if (pid != NULL)
		free(pid);
	return (status);
}
