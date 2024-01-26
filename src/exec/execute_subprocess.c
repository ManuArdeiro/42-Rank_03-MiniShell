/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_subprocess.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:50:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/26 19:50:14 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_isdefault_file(t_file *file)
{
	if (file == NULL)
		return (FALSE);
	return (ft_strequal(file->name, "STD"));
}

t_bool	ft_isemptycommand(t_command *command)
{
	if (command->name == NULL
		&& ((t_file *)command->infile->content)->mode != O_HEREDOC
		&& ft_isdefault_file((t_file *)command->infile->content) == FALSE)
		return (TRUE);
	return (FALSE);
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

	envp = ft_lstconvert_strarr(global->envlist, ENV);
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

	args = NULL;
	ft_open_filestreams(&infile, &outfile);
	if (infile->fd < 0)
		ft_terminateprocess(command, NULL, NULL, NO_SUCH_FILE_IN);
	if (outfile->fd < 0)
		ft_terminateprocess(command, NULL, NULL, NO_SUCH_FILE_OUT);
	if (ft_isemptycommand(command) == TRUE)
		ft_terminateprocess(command, NULL, NULL, NO_SUCH_FILE_IN);
	else if (command->name == NULL)
		ft_terminateprocess(command, NULL, NULL, NULL);
	ft_duplicate_descriptors(&infile->fd, &outfile->fd);
	ft_closefile(&infile->fd);
	ft_closefile(&outfile->fd);
	if (global->expand_startoken == TRUE)
		ft_checkfor_stars(command);
	args = ft_lstconvert_strarr(command->args, 0);
	ft_execute_givencommand(command, global, args);
}
