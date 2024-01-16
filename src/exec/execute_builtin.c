/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:00:10 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/24 16:44:22 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_redirect_streams(t_file *infile, t_file *outfile)
{
	ft_open_filestreams(&infile, &outfile);
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
	args = ft_lstconvert_strarr(command->args, 0);
	ft_clone_streams(&inputclone, &outputclone);
	ft_redirect_streams(
		(t_file *)command->infile->content,
		(t_file *)node->content
		);
	*pid = ft_builtins(args, global->envlist, global);
	ft_clear_strarray(args);
	ft_duplicate_descriptors(&inputclone, &outputclone);
	args = NULL;
}
