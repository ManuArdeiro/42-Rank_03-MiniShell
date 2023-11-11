/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:00:10 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/04 18:00:11 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void ft_revert_streamchange(int *inputclone, int *outputclone)
{
	if (*inputclone < 0 || *outputclone < 0)
		return ;
	if (dup2(*inputclone, STDIN_FILENO) < 0)
		ft_printerror(NULL, "Dup IN failed");
	if (dup2(*outputclone, STDOUT_FILENO) < 0)
		ft_printerror(NULL, "Dup OUT failed");
}

static void	ft_clone_streams(int *inputclone, int *outputclone)
{
	*inputclone = dup(STDIN_FILENO);
	*outputclone = dup(STDOUT_FILENO);
}

static void	ft_redirect_streams(t_file *infile, t_file *outfile)
{
	if (infile->name != NULL
		&& ft_strequal(infile->name, "STD") == FALSE
		&& ft_strnstr(infile->name, "pipe", 4) == NULL
		&& infile->mode != O_HEREDOC)
		infile->fd = ft_openfile(infile->name, infile->mode);
	if (outfile->name != NULL && ft_strequal(outfile->name, "STD") == FALSE
		&& ft_strnstr(infile->name, "pipe", 4) == NULL)
		outfile->fd = ft_openfile(outfile->name, outfile->mode);
	ft_duplicate_descriptors(&infile->fd, &outfile->fd);
	ft_closefile(&infile->fd);
	ft_closefile(&outfile->fd);
}


void	ft_execute_builtin(
			t_command *command, pid_t *pid, t_list *node, t_global *global)
{
	char	**args;
	int		inputclone;
	int		outputclone;

	inputclone = 0;
	outputclone = 0;
	if (command == NULL)
		return ;
	args = ft_lstconvert_strarr(command->args);
	ft_clone_streams(&inputclone, &outputclone);
	ft_redirect_streams(
		(t_file *)command->infile->content,
		(t_file *)node->content
		);
	*pid = ft_builtins(args, global->envlist, global);
	ft_clear_strarray(args);
	ft_revert_streamchange(&inputclone, &outputclone);
	args = NULL;
}
