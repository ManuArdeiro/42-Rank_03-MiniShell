/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_startoken.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:05:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/10 12:44:55 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_get_pathattributes(
	const char *fullpath,
	char **fileprefix, t_bool *stringpart, char *pathsuffix)
{
	char	*buffer;

	buffer = NULL;
	if (pathsuffix == NULL)
	{
		buffer = ft_strdup(fullpath);
		(*stringpart) = ft_get_stringpart(fullpath);
	}
	else
	{
		buffer = ft_strdup(pathsuffix);
		(*stringpart) = ft_get_stringpart(pathsuffix);
	}
	if (ft_endswith(buffer, "*") == TRUE)
		(*fileprefix) = ft_strtrim(buffer, "*");
	else if (buffer != NULL && ft_startswith(buffer, "*") == TRUE)
		(*fileprefix) = ft_strdup(buffer + 1);
	if (buffer != NULL)
		free(buffer);
}

static t_list	*ft_get_dirfiles(
		DIR *directory, char *path, char *pathsuffix, const char *fullpath)
{
	char	*fileprefix;
	t_list	*fileslist;
	t_bool	stringpart;
	char	*newpath;

	fileslist = NULL;
	newpath = NULL;
	fileprefix = NULL;
	stringpart = FALSE;
	ft_get_pathattributes(fullpath, &fileprefix, &stringpart, pathsuffix);
	if (ft_strlen(path) > 1)
		newpath = ft_strjoin(path, "/");
	else
		newpath = ft_strdup(path);
	fileslist
		= ft_get_directorylist(newpath, fileprefix, stringpart, directory);
	free(fileprefix);
	free(newpath);
	return (fileslist);
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
	fileslist = ft_get_dirfiles(directory, dirpath, pathsuffix, fullpath);
	if (dirpath != NULL)
		free(dirpath);
	if (fileslist == NULL)
		ft_lstinsert(&fileslist, ft_strdup(fullpath), BACK);
	if (directory != NULL)
		closedir(directory);
	return (fileslist);
}
