/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_filelist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:28:06 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/20 20:25:11 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_expand_filelist(t_list **filelist)
{
	t_list	*node;
	t_file	*file;
	t_file	*fullfile;

	if (filelist == NULL)
		return ;
	fullfile = NULL;
	node = *filelist;
	while (node != NULL)
	{
		file = (t_file *)node->content;
		if (file->mode == O_HEREDOC)
		{
			ft_get_heredoc(&file);
			ft_lstinsert(filelist, file, BACK);
		}
		node = node->next;
	}
	if (ft_lstsize(*filelist) > 1)
	{
		fullfile = ft_compress_filelist(*filelist);
		ft_lstinsert(filelist, fullfile, FRONT);
	}
}
