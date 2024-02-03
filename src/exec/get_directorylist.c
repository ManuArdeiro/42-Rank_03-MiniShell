/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_directorylist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:32:31 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/03 12:38:14 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_filename(const char *path, const char *d_name)
{
	char	*filename;

	filename = NULL;
	if (ft_strequal(path, ".") == TRUE)
		filename = ft_strdup(d_name);
	else
		filename = ft_strjoin(path, d_name);
	return (filename);
}

static char	*ft_get_dirfile(
	const char *path,
	struct dirent *dirent, char *fileprefix, t_bool stringpart)
{
	char	*filename;

	filename = NULL;
	if (fileprefix != NULL && *fileprefix != '\0' && *fileprefix != ' ')
	{
		if (stringpart == LAST)
		{
			if (ft_startswith(dirent->d_name, fileprefix) == TRUE)
				filename = ft_get_filename(path, dirent->d_name);
		}
		else if (stringpart == FIRST)
		{
			if (ft_endswith(dirent->d_name, fileprefix) == TRUE)
				filename = ft_get_filename(path, dirent->d_name);
		}
	}
	else if (*(dirent->d_name) != '.')
		filename = ft_get_filename(path, dirent->d_name);
	return (filename);
}

t_list	*ft_get_directorylist(
	char *path, char *fileprefix, t_bool stringpart, DIR *directory)
{
	struct dirent	*dirent;
	t_list			*fileslist;
	char			*dirfile;

	dirfile = NULL;
	fileslist = NULL;
	if (directory != NULL)
	{
		dirent = readdir(directory);
		while (dirent != NULL)
		{
			dirfile
				= ft_get_dirfile(path, dirent, fileprefix, stringpart);
			if (dirfile != NULL)
				ft_lstinsert(&fileslist, dirfile, BACK);
			dirent = readdir(directory);
		}
	}
	return (fileslist);
}
