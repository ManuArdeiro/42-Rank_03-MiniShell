/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_filecontent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:44:19 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/20 20:33:28 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_write_to_pipe(t_file *file, int *filepipe)
{
	char	*line;

	line = "";
	if (file == NULL || file->name == NULL)
		return ;
	file->fd = ft_openfile(file->name, file->mode);
	if (file->fd < 0)
		return ;
	while (line != NULL)
	{
		line = get_next_line(file->fd);
		if (line == NULL)
		{
			ft_closepipe(&filepipe[0], &filepipe[1]);
			ft_printerror(__func__, "Get Next Line");
		}
		ft_putstr_fd(line, filepipe[1]);
		free(line);
	}
}

static void	ft_wait_and_close(int child, t_file *file, int *herepipe)
{
	int		status;

	status = EXIT_SUCCESS;
	file->fd = dup(herepipe[0]);
	ft_closepipe(&herepipe[0], &herepipe[1]);
	if (waitpid(child, &status, EXIT_SUCCESS) < 0)
		ft_printerror(__func__, "Wait");
	ft_evaluate_subprocess(status);
}

static void	ft_read_and_append(
		t_file **fullfile, t_list *filelist, int *filepipe)
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
	}
	else if (child < 0)
		ft_printerror(__func__, "Fork");
	ft_wait_and_close(child, *fullfile, filepipe);
}

t_file	*ft_compress_filelist(t_list *filelist)
{
	t_file	*fullfile;
	int		filepipe[2];

	fullfile = NULL;
	if (filelist == NULL)
		return (NULL);
	fullfile = ft_create_file(ft_strdup("fullfile"), INFILE, O_APPEND);
	if (fullfile == NULL)
		return (NULL);
	if (pipe(filepipe) < 0)
		return (NULL);
	ft_read_and_append(&fullfile, filelist, filepipe);
	return (fullfile);
}
