/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_filelist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:28:06 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/10 14:02:11 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_file	*ft_copyfile(t_file *file)
{
	t_file	*newfile;

	if (file == NULL)
		return (NULL);
	newfile = malloc(sizeof(t_file));
	if (newfile == NULL)
		return (NULL);
	newfile->name = ft_strdup(file->name);
	newfile->fd = dup(file->fd);
	newfile->mode = file->mode;
	return (newfile);
}

static t_list	*ft_get_expandedfilelist(t_list *filelist, t_global *global)
{
	t_list	*node;
	t_list	*expandedlist;
	t_file	*file;

	expandedlist = NULL;
	node = filelist;
	file = NULL;
	while (node != NULL)
	{
		file = (t_file *)node->content;
		if (file != NULL && file->mode == O_HEREDOC)
		{
			ft_get_heredoc(&file, global);
			ft_lstinsert(&expandedlist, ft_copyfile(file), BACK);
		}
		else
			ft_lstinsert(&expandedlist, ft_copyfile(file), BACK);
		node = node->next;
	}
	return (expandedlist);
}

void	ft_expand_filelist(t_list **filelist, t_global *global)
{
	t_file	*fullfile;
	t_list	*expandedlist;

	expandedlist = NULL;
	if (filelist == NULL)
		return ;
	fullfile = NULL;
	expandedlist = ft_get_expandedfilelist(*filelist, global);
	if (ft_lstsize(expandedlist) > 1)
	{
		fullfile = ft_compress_filelist(expandedlist, global);
		if (fullfile != NULL)
			ft_lstinsert(filelist, fullfile, FRONT);
	}
	if (expandedlist != NULL)
		ft_lstclear(&expandedlist, ft_freefile);
}
