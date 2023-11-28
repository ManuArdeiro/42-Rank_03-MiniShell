/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_filelist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:28:06 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/28 19:27:59 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*ft_get_expandedfilelist(t_list *filelist)
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
			ft_get_heredoc(&file);
			ft_lstinsert(&expandedlist, file, BACK);
		}
		node = node->next;
	}
	return (expandedlist);
}

void	ft_expand_filelist(t_list **filelist)
{
	t_file	*fullfile;
	t_list	*expandedlist;
	char *s = NULL;
	expandedlist = NULL;
	if (filelist == NULL)
		return ;
	fullfile = NULL;
	expandedlist = ft_get_expandedfilelist(*filelist);
	if (ft_lstsize(expandedlist) > 1)
	{
		fullfile = ft_compress_filelist(expandedlist);
		read(fullfile->fd, s, 10);
		if (s != NULL)
			printf("s = %s\n", s);
		if (fullfile != NULL)
			ft_lstinsert(filelist, fullfile, FRONT);
	}
}
