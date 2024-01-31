/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_startoken.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:05:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/31 18:25:05 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//add suffix expansion

static void	ft_filter_path(
	const char *path,
	t_list **fileslist, struct dirent *dirent, char *fileprefix)
{
	if (fileprefix != NULL
		&& *fileprefix != '\0'
		&& *fileprefix != ' ')
	{
		if (ft_startswith(dirent->d_name, fileprefix) == TRUE)
		{
			if (ft_strequal(path, ".") == TRUE)
				ft_lstinsert(
					fileslist, ft_strdup((char *)dirent->d_name), BACK);
			else
				ft_lstinsert(fileslist,
					ft_strjoin(path, (char *)dirent->d_name), BACK);
		}
	}
	else if (*(dirent->d_name) != '.')
	{
		if (ft_strequal(path, ".") == TRUE)
			ft_lstinsert(
				fileslist, ft_strdup((char *)dirent->d_name), BACK);
		else
			ft_lstinsert(fileslist,
				ft_strjoin(path, (char *)dirent->d_name), BACK);
	}
}

static void	ft_add_dirfiles(
		t_list **fileslist, DIR *directory, char *path, char *pathsuffix)
{
	struct dirent	*dirent;
	int				pathlen;
	char			*fileprefix;

	fileprefix = ft_strstrip(pathsuffix);
	pathlen = ft_strlen(path);
	if (pathlen > 1)
		path = ft_strjoin_get(path, "/");
	if (directory != NULL)
	{
		dirent = readdir(directory);
		while (dirent != NULL)
		{
			ft_filter_path(path, fileslist, dirent, fileprefix);
			dirent = readdir(directory);
		}
	}
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
	system("leaks minishell");
	return (fileslist);
}
