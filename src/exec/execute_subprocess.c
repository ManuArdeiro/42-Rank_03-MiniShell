/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_subprocess.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:50:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/09 19:06:05 by yzaytoun         ###   ########.fr       */
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
	free(pathvariables);
	if (execve(command->name, args, envp) < 0)
	{
		ft_clear_strarray(envp);
		ft_clear_strarray(args);
		ft_putstr_fd("MiniShell: command not found: ", STDERR_FILENO);
		ft_putstr_fd(command->name, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		ft_free_commandlist(&command);
		exit(127);
	}
}

static void	ft_execute_builtincommand(char **args, t_global *global)
{
	if (ft_builtins(args, global->envlist, global) == EXIT_FAILURE)
	{
		ft_putstr_fd("MiniShell: command not found: ", STDERR_FILENO);
		ft_putstr_fd(args[0], STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		ft_clear_strarray(args);
		exit(127);
	}
	exit(EXIT_SUCCESS);
}

void	ft_execute_subprocess(
		t_command *command, t_file *infile, t_file *outfile, t_global *global)
{
	char	**args;

	args = NULL;
	infile->fd[0] = ft_openfile(infile->name, infile->mode);
	outfile->fd[0] = ft_openfile(outfile->name, outfile->mode);
	ft_duplicate_descriptors(&infile->fd[0], &outfile->fd[0]);
	ft_closefile(&infile->fd[0]);
	ft_closefile(&outfile->fd[0]);
	args = ft_lstconvert_strarr(command->args);
	if (ft_isbuiltin(command->name) == TRUE)
		ft_execute_builtincommand(args, global);
	else
		ft_execute_givencommand(command, global, args);
}
