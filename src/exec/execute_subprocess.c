/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_subprocess.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:50:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/16 20:16:33 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_terminateprocess(
	t_command *command, char **args, char **envp, t_bool option
)
{
	ft_clear_strarray(envp);
	ft_clear_strarray(args);
	ft_print_commanderror(command->name, option);
	ft_free_commandlist(&command);
	if (option == PERMISSION_DENIED)
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
	else if (execve(command->name, args, envp) < 0)
		ft_terminateprocess(command, args, envp, FALSE);
}

void	ft_execute_subprocess(
		t_command *command, t_file *infile, t_file *outfile, t_global *global)
{
	char	**args;
	char	*shelvl;

	args = NULL;
	shelvl = NULL;
	ft_open_filestreams(&infile, &outfile);
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
