/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executecommand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:44:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/13 20:32:14 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_eval_processstatus(int status)
{
	int	exitstatus;

	exitstatus = 0;
	if (WIFEXITED(status))
	{
		exitstatus = WEXITSTATUS(status);
		if (exitstatus != EXIT_SUCCESS)
			return (exitstatus);
	}
	return (EXIT_SUCCESS);
}

static void	ft_childprocess(t_command *command, char **envp)
{
	command->infile[0].fd = ft_openfile(command->infile[0].name, O_RDONLY);
	command->outfile[0].fd = ft_openfile(command->outfile[0].name, O_RDWR);
	ft_duplicate_descriptors(&command->infile[0].fd, &command->outfile[0].fd);
	ft_closefile(&command->infile[0].fd);
	ft_closefile(&command->outfile[0].fd);
	if (execve(command->name, command->args, envp) < 0)
	{
		ft_printerror(NULL, "No such file or directory");
		exit(127);
	}
}

int	ft_executecommand(t_command *command, char **envp)
{
	pid_t	pid;
	int		status;

	if (command == NULL)
		return (0);
	pid = fork();
	if (pid == 0)
		ft_childprocess(command, envp);
	else if (pid < 0)
		ft_printerror(__func__, "Fork");
	if (waitpid(pid, &status, EXIT_SUCCESS) < 0)
		ft_printerror(__func__, "wait");
	return (ft_eval_processstatus(status));
}
