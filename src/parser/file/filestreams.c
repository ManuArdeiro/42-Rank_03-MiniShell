/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filestreams.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:49:52 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/19 19:09:10 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_openfile(char *filename, int mode)
{
	int	file_descriptor;

	file_descriptor = -1;
	if (filename == NULL)
		return (file_descriptor);
	if (mode == O_RDONLY)
		file_descriptor = open(filename, mode);
	else if (mode == O_RDWR)
		file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (mode == O_APPEND)
		file_descriptor = open(filename, O_RDWR | O_CREAT | O_APPEND, 0644);
	return (file_descriptor);
}

void	ft_closefile(int *file_descriptor)
{
	if (*file_descriptor < 0 || *file_descriptor == STDIN_FILENO
		|| *file_descriptor == STDOUT_FILENO)
		return ;
	if (close(*file_descriptor) < 0)
		ft_printerror(__func__, "close");
}

void	ft_duplicate_descriptors(int *input, int *output)
{
	if (*input != STDIN_FILENO && *input > 0)
	{
		if (dup2(*input, STDIN_FILENO) < 0)
			ft_printerror(NULL, "Dup IN failed");
	}
	if (*output != STDOUT_FILENO && *output > 0)
	{
		if (dup2(*output, STDOUT_FILENO) < 0)
			ft_printerror(NULL, "Dup OUT failed");
	}
}

void	ft_open_filestreams(t_file **infile, t_file **outfile)
{
	if (ft_strequal((*infile)->name, "STD") == FALSE
		&& (*infile)->mode != O_HEREDOC)
		(*infile)->fd = ft_openfile((*infile)->name, (*infile)->mode);
	if (ft_strequal((*outfile)->name, "STD") == FALSE
		&& (*outfile)->mode != O_HEREDOC)
		(*outfile)->fd = ft_openfile((*outfile)->name, (*outfile)->mode);
}

void	ft_clone_streams(int *inputclone, int *outputclone)
{
	*inputclone = dup(STDIN_FILENO);
	*outputclone = dup(STDOUT_FILENO);
}
