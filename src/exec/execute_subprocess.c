/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_subprocess.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:50:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/25 18:28:03 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_execute_givencommand(
		t_command *command, t_global *global, char **args)
{
	char	**envp;

	envp = ft_lstconvert_strarr(global->envlist);
	if (execve(command->name, args, envp) < 0)
	{
		ft_printerror(NULL, "No such file or directory");
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
	ft_closefile(&infile->fd);
	ft_closefile(&outfile->fd);
	args = ft_lstconvert_strarr(command->args);
	printf("command name = %s\n", command->name);
	if (ft_isbuiltin(command->name) == TRUE)
		ft_execute_builtin(global, args);
	else
		ft_execute_givencommand(command, global, args);
}
