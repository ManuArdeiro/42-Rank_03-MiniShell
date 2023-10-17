/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pathprefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:37:20 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/17 20:47:04 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_add_pathprefix(char *commandname, t_list *envlist)
{
	char	**pathlist;
	char	*path;
	int		count;
	char	*buffer;
	char	*buffer2;

	count = 0;
	buffer = NULL;
	path = ft_getenv("PATH", envlist);
	pathlist = ft_split(path, ':');
	while (pathlist[count] != NULL)
	{
		buffer2 = ft_strjoin("/", commandname);
		buffer = ft_strjoin(pathlist[count], buffer2);
		free(buffer2);
		if (access(buffer, X_OK) == 0)
		{
			free(commandname);
			return (buffer);
		}
		free(buffer);
		++count;
	}
	free(path);
	ft_clear_strarray(pathlist);
	return (commandname);
}
