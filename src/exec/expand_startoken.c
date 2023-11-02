/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_startoken.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:05:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/02 19:32:57 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_add_dir(t_list **files_list, DIR *directory, char *path)
{
	struct dirent	*dirent;

	if (directory != NULL)
	{
		dirent = readdir(directory);
		while (dirent != NULL)
		{
			if (path[0] == '.')
				ft_lstinsert(
					files_list, ft_strdup((char *)dirent->d_name), BACK);
			else
				ft_lstinsert(
					files_list,
					ft_strjoin(path, (char *)dirent->d_name), BACK);
			dirent = readdir(directory);
		}
	}
}

t_list	*ft_expand_startoken(char *fullpath)
{
	char			*path;
	DIR				*directory;
	t_list			*files_list;
	int				lastpos;

	files_list = NULL;
	path = NULL;
	if (fullpath == NULL)
		return (NULL);
	lastpos = ft_chrcount(fullpath, '/');
	path = ft_strchr_pos(fullpath, '/', lastpos);
	if (path == NULL)
		path = ".";
	directory = opendir(path);
	ft_add_dir(&files_list, directory, path);
	return (files_list);
}
