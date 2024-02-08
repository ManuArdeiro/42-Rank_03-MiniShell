/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_filecontent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:44:19 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/08 18:30:50 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_write_to_pipe(t_file *file, int *filepipe)
{
	char	*line;

	line = "";
	if (file == NULL || file->name == NULL)
		return ;
	if (file->mode != O_HEREDOC)
	{
		file->fd = ft_openfile(file->name, file->mode);
		if (file->fd < 0)
			return ;
	}
	while (line != NULL)
	{
		line = get_next_line(file->fd);
		if (line != NULL)
			ft_putstr_fd(line, filepipe[1]);
		free(line);
	}
	ft_closefile(&file->fd);
}

static void	ft_read_and_append(
		t_file **fullfile, t_list *filelist, int *filepipe, t_global *global)
{
	t_list	*node;
	pid_t	child;

	child = fork();
	if (child == 0)
	{
		node = filelist;
		while (node != NULL)
		{
			ft_write_to_pipe((t_file *)node->content, filepipe);
			node = node->next;
		}
		ft_closepipe(&filepipe[0], &filepipe[1]);
		exit(EXIT_SUCCESS);
	}
	else if (child < 0)
		ft_printerror(__func__, "Fork");
	ft_wait_close_heredoc(child, *fullfile, filepipe, global);
}

t_file	*ft_compress_filelist(t_list *filelist, t_global *global)
{
	t_file	*fullfile;
	int		filepipe[2];

	fullfile = NULL;
	if (filelist == NULL)
		return (NULL);
	fullfile = ft_create_file("fullfile", INFILE, O_HEREDOC);
	if (fullfile == NULL)
		return (NULL);
	if (pipe(filepipe) < 0)
		return (NULL);
	ft_read_and_append(&fullfile, filelist, filepipe, global);
	return (fullfile);
}
