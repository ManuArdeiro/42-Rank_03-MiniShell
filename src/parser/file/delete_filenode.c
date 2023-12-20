/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_filenode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:00:41 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/20 19:02:13 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_delete_filenode(t_list **filelist, char *file_todelete)
{
	t_list	*node;
	t_file	*file;
	t_list	*prevnode;

	if (filelist == NULL)
		return ;
	node = *filelist;
	prevnode = NULL;
	while (node != NULL)
	{
		file = (t_file *)node->content;
		if (ft_strequal(file->name, file_todelete) == TRUE)
		{
			prevnode->next = node->next;
			ft_freefile(node->content);
			free(node);
			return ;
		}
		prevnode = node;
		node = node->next;
	}
}
