/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:44:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/01 19:01:34 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_eval_processstatus(int status)
{
	int	exitstatus;

	exitstatus = 0;
	if (WIFEXITED(status))
	{
		exitstatus = WEXITSTATUS(status);
		if (exitstatus != EXIT_SUCCESS)
			exit(exitstatus);
	}
}

t_bool	ft_execute(char *commandname, char **args, t_list *envlist)
{
	if (commandname == NULL)
		return (EXITED);
	if (execve(commandname, args, envlist) < 0)
	{
		ft_printerror(__func__, "execve");
		exit(EXIT_FAILURE);
	}
}

static void	ft_childprocess(
		t_command *command, t_file infile, t_file outfile, t_list *envlist)
{
	ft_openfile(outfile.name, O_WRONLY);
	ft_duplicate_descriptors(&infile.fd, &outfile.fd);
	ft_closefile(&infile.fd);
	ft_closefile(&outfile.fd);
	if (ft_execute(command->name, command->args, envlist) == EXITED)
		exist(EXIT_FAILURE);
}

void	ft_executecommand(t_command *command, t_list *envlist)
{
	int		count;
	pid_t	pid;
	int		status;

	count = 0;
	if (command == NULL)
		return ;
	command->infile[0].fd = ft_openfile(command->infile[0].name, O_RDONLY);
	while (command->outfile[count].name != NULL)
	{
		pid = fork();
		if (pid == 0)
			ft_childprocess(
				command,
				command->infile[0],
				command->outfile[count],
				envlist);
		else if (pid < 0)
			ft_printerror(__func__, "Fork");
		++count;
	}
	if (waitpid(pid, &status, EXIT_SUCCESS) < 0)
		ft_printerror(__func__, "wait");
	ft_eval_processstatus(status);
}
