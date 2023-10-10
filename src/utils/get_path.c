/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:46:11 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/05 11:17:36 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function returns the local path using the unistd.h library 
	function.	*/

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

/*	This function returns the root directory (for 42 computers) of the
	path passed as argument.	*/

char	*ft_get_rootpath(const char *path)
{
	char	*rootpath;
	char	*pathsuffix;
	size_t	suffix_len;
	size_t	path_len;

	if (path == NULL)
		return (NULL);
	pathsuffix = ft_strchr_pos(path, '/', 3);
	suffix_len = ft_strlen(pathsuffix);
	path_len = ft_strlen(path);
	rootpath = malloc(suffix_len + path_len + 1);
	if (!rootpath)
		return (NULL);
	ft_strlcpy(rootpath, path, path_len - suffix_len + 2);
	return (rootpath);
}
