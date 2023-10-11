/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:03:52 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/11 11:55:50 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_openfile(char *filename, int mode)
{
	int	file_descriptor;

	file_descriptor = -1;
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
	if (close(*file_descriptor) < 0)
		ft_printerror(__func__, "close");
}

void	ft_duplicate_descriptors(int *input, int *output)
{
	if (*input != STDIN_FILENO)
		if (dup2(*input, STDIN_FILENO) < 0)
			ft_printerror(NULL, "Dup IN failed");
	if (*output != STDOUT_FILENO)
		if (dup2(*output, STDOUT_FILENO) < 0)
			ft_printerror(NULL, "Dup OUT failed");
}
