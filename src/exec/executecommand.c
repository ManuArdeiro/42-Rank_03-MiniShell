/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executecommand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:44:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/21 19:00:27 by yzaytoun         ###   ########.fr       */
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
		{
			printf("Process Exited with status -> %d \n", exitstatus);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

static void	ft_execute(
	t_command *command, t_file infile, t_file outfile, char **envp)
{
	if (infile.name != NULL)
		infile.fd = ft_openfile(infile.name, infile.mode);
	if (outfile.name != NULL)
		outfile.fd = ft_openfile(outfile.name, outfile.mode);
	ft_duplicate_descriptors(&infile.fd, &outfile.fd);
	ft_closefile(&infile.fd);
	ft_closefile(&outfile.fd);
	if (execve(command->name, command->args, envp) < 0)
	{
		ft_printerror(NULL, "No such file or directory");
		exit(127);
	}	
}

///NOTE - HAndles one infile
static int	ft_initiate_childprocess(
		t_command *command, pid_t **pid, t_global *global)
{
	int		count;
	int		pidcount;
	char	**envp;

	count = 0;
	///get file array
	pidcount = ft_filelist_size(command->outfile);
	if (pidcount == 0)
		pidcount = 1;
	*pid = malloc(sizeof(pid_t) * pidcount);
	if (!*pid)
		return ;
	envp = ft_lstconvert_strarr(global->envlist);
	while (count < pidcount)
	{
		(*pid)[count] = fork();
		if ((*pid)[count] == 0)
		{
			if (ft_isbuiltin(command->name) == TRUE)
				ft_builtins(command->args, global->envlist, global);
			ft_execute(
				command, command->infile[0], command->outfile[count], envp);

		}
		else if ((*pid)[count] < 0)
			ft_printerror(NULL, "Fork");
		++count;
	}
	return (pidcount);
}

static int	ft_waitprocess(pid_t *pid, int pidcount)
{
	int	count;
	int	status;
	int	laststatus;

	status = EXIT_SUCCESS;
	laststatus = EXIT_SUCCESS;
	if (pidcount == 0)
		pidcount = 1;
	count = 0;
	while (count < pidcount)
	{
		if (waitpid(pid[count], &status, EXIT_SUCCESS) < 0)
			laststatus = ft_eval_processstatus(status);
		++count;
	}
	return (laststatus);
}

t_bool	ft_executecommand(t_command *command, char **envp, t_global *global)
{
	pid_t	*pidarray;
	char	*pathvariables;
	int		pidcount;

	pidarray = NULL;
	if (command == NULL)
		return ;
	ft_printcommand(command);
	//Expand *
	//Expand dollar
	pidcount = ft_initiate_childprocess(command, &pidarray, global);
	global->laststatus = ft_waitprocess(pidarray, pidcount);
}
