/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_subprocess.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:50:44 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/04 18:01:11 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_fork_subprocess(
			t_command *command, pid_t *pid, t_list *node, t_global *global)
{
	*pid = fork();
	if (*pid == 0)
	{
		global->signallist.__sigaction_u.__sa_handler = &handle_sigint_exit;
		sigaction(SIGINT, &global->signallist, NULL);
		ft_execute_subprocess(command,
			(t_file *)command->infile->content,
			(t_file *)node->content,
			global);
	}
	else if (*pid < 0)
		ft_printerror(NULL, "Fork");
}

static void	ft_initiate_subprocess(
			t_command *command, pid_t **pid, int pidcount, t_global *global)
{
	t_list	*node;
	int		count;

	count = 0;
	if (command == NULL || *pid == NULL || global == NULL)
		return ;
	node = command->outfile;
	global->signallist.__sigaction_u.__sa_handler = &handle_sigint2;
	sigaction(SIGINT, &global->signallist, NULL);
	global->signallist.__sigaction_u.__sa_handler = &ft_signal_handler;
	sigaction(SIGQUIT, &global->signallist, NULL);
	while (count < pidcount && node != NULL)
	{
		if (ft_isbuiltin(command->name) == TRUE)
			ft_execute_builtin(command, &(*pid)[count], node, global);
		else
			ft_fork_subprocess(command, &(*pid)[count], node, global);
		node = node->next;
		++count;
	}
}

int	ft_create_subprocess(t_command *command, pid_t **pid, t_global *global)
{
	int		pidcount;

	pidcount = ft_lstsize(command->outfile);
	if (pidcount == 0)
		pidcount = 1;
	*pid = malloc(sizeof(pid_t) * pidcount);
	if (!*pid)
		return (0);
	ft_initiate_subprocess(command, pid, pidcount, global);
	return (pidcount);
}
