/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_star.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:05:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/20 18:58:17 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_expand_startoken(char *fullpath)
{
	char			*path;
	DIR				*directory;
	struct dirent	*dirent;
	t_list			*files_list;

	files_list = NULL;
	if (path == NULL)
		return (NULL);
	path = ft_strrchr(fullpath, "/");
	if (path == NULL)
		path = ".";
	printf("path = %s\n", path);
	directory = opendir(path);
	dirent = readdir(directory);
	while (dirent != NULL)
	{
		if (dirent != NULL)
			ft_lstinsert(&files_list, (char *)dirent->d_name, BACK);
		dirent = readdir(directory);
	}
}
