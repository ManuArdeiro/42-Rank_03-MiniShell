/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_subprocess.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:50:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/26 21:08:01 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_execute_givencommand(
		t_command *command, t_global *global, char **args)
{
	char	**envp;
	char	*pathvariables;

	envp = ft_lstconvert_strarr(global->envlist);
	pathvariables = ft_getenv("PATH", global->envlist);
	command->name = ft_add_pathprefix(command->name, pathvariables);
	if (execve(command->name, args, envp) < 0)
	{
		ft_putstr_fd("MiniShell: command not found: ", STDERR_FILENO);
		ft_putstr_fd(command->name, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		exit(127);
	}
}

static void	ft_execute_builtin(t_global *global, char **args)
{
	if (ft_builtins(args, global->envlist, global) == EXIT_FAILURE)
	{
		ft_printerror(NULL, "No such file or directory");
		exit(127);
	}
	else
		exit(EXIT_SUCCESS);
}

void	ft_execute_subprocess(
		t_command *command, t_file *infile, t_file *outfile, t_global *global)
{
	char	**args;

	args = NULL;
	if (infile->name != NULL && ft_strequal(infile->name, "STD") == FALSE)
		infile->fd = ft_openfile(infile->name, infile->mode);
	if (outfile->name != NULL && ft_strequal(outfile->name, "STD") == FALSE)
		outfile->fd = ft_openfile(outfile->name, outfile->mode);
	ft_duplicate_descriptors(&infile->fd, &outfile->fd);
	if (infile->fd != STDIN_FILENO)
		ft_closefile(&infile->fd);
	if (outfile->fd != STDOUT_FILENO)
		ft_closefile(&outfile->fd);
	args = ft_lstconvert_strarr(command->args);
	if (ft_isbuiltin(command->name) == TRUE)
		ft_execute_builtin(global, args);
	else
		ft_execute_givencommand(command, global, args);
}
