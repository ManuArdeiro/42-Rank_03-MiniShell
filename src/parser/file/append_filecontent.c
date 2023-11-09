/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_filecontent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:44:19 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/04 17:51:38 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_readfile(t_file	*file)
{
	char	*buffer;
	char	*line;

	line = "";
	buffer = NULL;
	if (file == NULL || file->name == NULL)
		return (NULL);
	file->fd[0] = ft_openfile(file->name, file->mode);
	if (file->fd[0] < 0)
		return (NULL);
	while (line != NULL)
	{
		line = get_next_line(file->fd[0]);
		if (line != NULL)
			buffer = ft_strjoin_get(buffer, line);
		free(line);
	}
	return (buffer);
}

static void	ft_read_and_append(t_file **fullfile, t_list *filelist)
{
	t_list	*node;
	char	*buffer;

	node = filelist;
	buffer = NULL;
	while (node != NULL)
	{
		buffer = ft_readfile((t_file *)node->content);
		ft_putstr_fd(buffer, (*fullfile)->fd[0]);
		node = node->next;
	}
}

t_file	*ft_compress_filelist(t_list *filelist)
{
	t_file	*fullfile;

	fullfile = NULL;
	if (filelist == NULL)
		return (NULL);
	fullfile = ft_create_file(ft_strdup("obj/fullinfile"), INFILE, O_APPEND);
	if (fullfile == NULL)
		return (NULL);
	fullfile->fd[0] = ft_openfile(fullfile->name, fullfile->mode);
	if (fullfile->fd[0] < 0)
		return (NULL);
	ft_read_and_append(&fullfile, filelist);
	fullfile->mode = O_RDONLY;
	close(fullfile->fd[0]);
	return (fullfile);
}
