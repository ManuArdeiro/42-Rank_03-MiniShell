/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:46:11 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/16 19:01:02 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_localpath(void)
{
	char	*localdir;

	localdir = malloc(PATH_MAX);
	if (!localdir)
		return (NULL);
	if (getcwd(localdir, PATH_MAX) == NULL)
		return (NULL);
	return (localdir);
}

char	*ft_get_rootpath(const char *path)
{
	char	*rootpath;
	char	*pathsuffix;
	size_t	suffix_len;
	size_t	path_len;

	if (path == NULL)
		return (NULL);
	pathsuffix = ft_strchr_pos(path, '/', 3);
	suffix_len = ft_strlen(pathsuffix) + 1;
	path_len = ft_strlen(path) + 1;
	rootpath = malloc(suffix_len + path_len);
	printf("len = %lu", suffix_len + path_len);
	if (!rootpath)
		return (NULL);
	ft_strlcpy(rootpath, path, path_len - suffix_len);
	printf("root = %s", rootpath);
	return (rootpath);
}
