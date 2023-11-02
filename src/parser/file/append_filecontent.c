/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_filecontent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:44:19 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/02 20:53:54 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_file	*ft_append_filecontent(t_list *filelist)
{
	t_list	*node;
	t_file	*fullfile;
	char	*buffer;

	fullfile = NULL;
	if (filelist == NULL)
		return (NULL);
	node = filelist;
	while (node != NULL)
	{
		buffer = ft_readfromfile((t_file *)node->content);
		ft_writetofile(fullfile, buffer);
		node = node->next;
	}
	return (fullfile);
}
