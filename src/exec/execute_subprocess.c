/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_subprocess.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:50:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/16 17:53:07 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_checkfor_stars(t_command *command)
{
	t_list	*starnode;

	if (command == NULL)
		return ;
	starnode = ft_get_lstnode(command->args, "*");
	if (starnode != NULL)
	{
		ft_print_commanderror((char *)starnode->content, TRUE);
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
	if (access(command->name, F_OK) == 0
		&& access(command->name, X_OK) != 0)
		printf("permission denied\n");
	free(pathvariables);
	if (execve(command->name, args, envp) < 0)
	{
		ft_clear_strarray(envp);
		ft_clear_strarray(args);
		ft_print_commanderror(command->name, FALSE);
		ft_free_commandlist(&command);
		exit(127);
	}
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
	ft_checkfor_stars(command);
	args = ft_lstconvert_strarr(command->args);
	ft_execute_givencommand(command, global, args);
}
