/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_subprocess.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:50:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/20 20:31:37 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_is_directory(const char *path)
{
	struct stat	statbuf;
	int			status;

	status = FALSE;
	if (path == NULL)
		return (0);
	if (stat(path, &statbuf) != 0)
		return (0);
	status = S_ISDIR(statbuf.st_mode);
	return (status);
}

static void	ft_terminateprocess(
	t_command *command, char **args, char **envp, const char *errortype
)
{
	ft_clear_strarray(envp);
	ft_clear_strarray(args);
	if (ft_strequal(errortype, NO_SUCH_FILE_OUT) == TRUE)
		ft_print_commanderror(
			((t_file *)command->outfile->content)->name, NO_SUCH_FILE);
	else if (ft_strequal(errortype, NO_SUCH_FILE_IN) == TRUE)
		ft_print_commanderror(
			((t_file *)command->infile->content)->name, NO_SUCH_FILE);
	else
		ft_print_commanderror(command->name, errortype);
	ft_free_commandlist(&command);
	if (ft_strequal(errortype, PERMISSION_DENIED) == TRUE
		|| ft_strequal(errortype, IS_DIRECTORY) == TRUE)
		exit(126);
	else
		exit(127);
}

static void	ft_checkfor_stars(t_command *command)
{
	t_list	*starnode;

	if (command == NULL)
		return ;
	starnode = ft_get_lstnode(command->args, "*");
	if (starnode != NULL)
	{
		ft_print_commanderror((char *)starnode->content, STAR);
		ft_free_commandlist(&command);
		exit(127);
	}
}

static void	ft_execute_givencommand(
		t_command *command, t_global *global, char **args)
{
	char	**envp;
	char	*pathvariables;

	envp = ft_lstconvert_strarr(global->envlist);
	pathvariables = ft_getenv("PATH", global->envlist);
	if (ft_strlen(command->name) > 0)
		command->name = ft_add_pathprefix(command->name, pathvariables);
	free(pathvariables);
	if (access(command->name, F_OK) == 0
		&& access(command->name, X_OK) != 0)
		ft_terminateprocess(command, args, envp, PERMISSION_DENIED);
	else if (ft_is_directory(command->name) != FALSE)
		ft_terminateprocess(command, args, envp, IS_DIRECTORY);
	else if (execve(command->name, args, envp) < 0)
		ft_terminateprocess(command, args, envp, COMMAND_NOT_FOUND);
}

void	ft_execute_subprocess(
		t_command *command, t_file *infile, t_file *outfile, t_global *global)
{
	char	**args;
	char	*shelvl;

	args = NULL;
	shelvl = NULL;
	ft_open_filestreams(&infile, &outfile);
	if (infile->fd < 0)
		ft_terminateprocess(command, NULL, NULL, NO_SUCH_FILE_IN);
	if (outfile->fd < 0)
		ft_terminateprocess(command, NULL, NULL, NO_SUCH_FILE_OUT);
	ft_duplicate_descriptors(&infile->fd, &outfile->fd);
	ft_closefile(&infile->fd);
	ft_closefile(&outfile->fd);
	if (ft_strequal(command->name, "./minishell") == TRUE)
	{
		shelvl = ft_getenv("SHLVL", global->envlist);
		if (shelvl != NULL)
			ft_lstinsert(&command->args, shelvl, BACK);
	}
	if (global->expand_startoken == TRUE)
		ft_checkfor_stars(command);
	args = ft_lstconvert_strarr(command->args);
	ft_execute_givencommand(command, global, args);
}
