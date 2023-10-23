/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_startoken.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:05:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/21 12:47:29 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_expand_startoken(char *fullpath)
{
	char			*path;
	DIR				*directory;
	struct dirent	*dirent;
	t_list			*files_list;
	int				lastpos;

	files_list = NULL;
	if (path == NULL)
		return (NULL);
	lastpos = ft_countchr(fullpath, '/');
	path = ft_strchr_pos(fullpath, '/', lastpos);
	if (path == NULL)
		path = ".";
	printf("path = %s\n", path);
	directory = opendir(path);
	if (directory != NULL)
		dirent = readdir(directory);
	while (dirent != NULL)
	{
		ft_lstinsert(
			&files_list,
			ft_strjoin(path, (char *)dirent->d_name), BACK);
		dirent = readdir(directory);
	}
	return (files_list);
}
