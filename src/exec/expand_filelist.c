/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_filelist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:28:06 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/08 19:28:08 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_expand_filelist(t_list **filelist)
{
	t_list	*node;
	t_file	*file;

	if (filelist == NULL)
		return ;
	node = *filelist;
	while (node != NULL)
	{
		file = (t_file *)node->content;
		if (file->mode == O_HEREDOC)
			ft_get_heredoc(&file);
		node = node->next;
	}
}
