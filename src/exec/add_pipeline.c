/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:13:18 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/21 20:54:01 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_addpipe(t_command *command, int *pipe, t_bool std_stream)
{
	t_file	*pipestream:

	if (command == NULL || pipe == 0)
		return ;
	pipestream = ft_create_file(ft_strdup("in_pipe"),);
	//pipename
	//descriptor
	if (std_stream == INFILE)
		ft_lstinsert(&command->infile, pipe, BACK);
	else if (std_stream == OUTFILE)
		ft_lstinsert(&command->outfile, pipe, FRONT);
}

int	ft_add_pipeline(t_minitree *root)
{
	int			status;
	t_minitree	*last_leftnode;
	t_minitree	*first_rightnode;

	if (root == NULL)
		return (EXITED);
	status = EXIT_SUCCESS;
	last_leftnode = ft_get_lasttreenode(root, RIGHT);
	first_rightnode = root->rightchild;
	if (ft_is_emptynode(root->leftchild) == FALSE
		&& ft_is_emptynode(root->rightchild) == FALSE)
	{
		ft_addpipe(
			(t_command *)
			((t_mininode *)last_leftnode->content)->content,
			(int *)root->content,
			INFILE);
		ft_addpipe(
			(t_command *)
			((t_mininode *)first_rightnode->content)->content,
			(int *)root->content,
			OUTFILE);
	}
	return (status);
}
