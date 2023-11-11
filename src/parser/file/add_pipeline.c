/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:13:18 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/02 20:39:28 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_addpipe(t_command *command, int *pipe, t_bool std_stream)
{
	t_file	*pipestream;

	if (command == NULL || pipe == 0)
		return ;
	if (std_stream == INFILE)
	{
		pipestream = ft_create_file(ft_strdup("in_pipe"), pipe[0], std_stream);
		ft_lstinsert(&command->infile, pipestream, FRONT);
	}
	else if (std_stream == OUTFILE)
	{
		pipestream = ft_create_file(ft_strdup("out_pipe"), pipe[1], std_stream);
		ft_lstinsert(&command->outfile, pipestream, FRONT);
	}
}

static void	ft_add_tochild(
		t_minitree *root, t_minitree *lastleft, t_minitree *firstright)
{
	t_command	*command;

	command = NULL;
	if (lastleft != NULL)
	{
		command = (t_command *)((t_mininode *)lastleft->content)->content;
		ft_addpipe(command, (int *)root->content, OUTFILE);
		ft_delete_filenode(&command->outfile, "STD");
	}
	if (firstright != NULL)
	{
		command = (t_command *)((t_mininode *)firstright->content)->content;
		ft_addpipe(command, (int *)root->content, INFILE);
		ft_delete_filenode(&command->infile, "STD");
	}
}

void	ft_add_pipeline(t_minitree *root)
{
	t_minitree	*lastleft;
	t_minitree	*firstright;

	if (root == NULL)
		return ;
	lastleft = NULL;
	firstright = NULL;
	firstright = ft_get_lasttreenode(root->rightchild, LEFT);
	if (ft_is_emptynode(root->leftchild) == FALSE
		&& ft_is_emptynode(root->rightchild) == FALSE
		&& ((t_mininode *)root->content)->type == n_or)
	{
		lastleft = ft_get_lasttreenode(root, RIGHT);
		ft_add_tochild(root, lastleft, firstright);
		lastleft = ft_get_lasttreenode(root, LEFT);
		ft_add_tochild(root, lastleft, NULL);
	}
	else
	{
		if (ft_is_emptynode(root->leftchild) == FALSE)
			lastleft = ft_get_lasttreenode(root->leftchild, RIGHT);
		ft_add_tochild(root, lastleft, firstright);
	}
}
