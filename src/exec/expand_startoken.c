/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_startoken.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:05:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/02 16:29:55 by yzaytoun         ###   ########.fr       */
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

static void	ft_add_dirfiles(
		t_list **fileslist, DIR *directory, char *path, char *pathsuffix)
{
	struct dirent	*dirent;
	char			*fileprefix;
	char			*dirfile;

	dirfile = NULL;
	fileprefix = ft_strstrip(pathsuffix);
	if (ft_strlen(path) > 1)
		path = ft_strjoin_get(path, "/");
	if (directory != NULL)
	{
		dirent = readdir(directory);
		while (dirent != NULL)
		{
			dirfile
				= ft_get_dirfile(path, dirent,
					fileprefix, ft_get_stringpart(pathsuffix));
			if (dirfile != NULL)
				ft_lstinsert(fileslist, dirfile, BACK);
			dirent = readdir(directory);
		}
	}
	free(fileprefix);
}

static char	*ft_get_dirpath(const char *fullpath, char **pathsuffix)
{
	char	*path;
	char	*pathlimit;
	int		lastpos;

	path = NULL;
	pathlimit = NULL;
	lastpos = 0;
	if (ft_strchr(fullpath, '/') != NULL)
	{
		lastpos = ft_chrcount(fullpath, '/');
		pathlimit = ft_strchr_pos(fullpath, '/', lastpos);
		path = ft_cutstr(fullpath, pathlimit);
		*pathsuffix = ft_strrchr(fullpath, '/');
		if (*pathsuffix != NULL)
			(*pathsuffix)++;
	}
	else
		path = ft_strdup(".");
	return (path);
}

t_list	*ft_expand_startoken(const char *fullpath)
{
	char	*dirpath;
	DIR		*directory;
	t_list	*fileslist;
	char	*pathsuffix;

	fileslist = NULL;
	dirpath = NULL;
	pathsuffix = NULL;
	directory = NULL;
	if (fullpath == NULL)
		return (NULL);
	dirpath = ft_get_dirpath(fullpath, &pathsuffix);
	if (dirpath != NULL)
		directory = opendir(dirpath);
	ft_add_dirfiles(&fileslist, directory, dirpath, pathsuffix);
	if (dirpath != NULL)
		free(dirpath);
	if (fileslist == NULL)
		ft_lstinsert(&fileslist, ft_strdup(fullpath), BACK);
	closedir(directory);
	return (fileslist);
}
