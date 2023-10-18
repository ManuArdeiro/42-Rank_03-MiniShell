/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pathprefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:37:20 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/18 18:17:52 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_add_pathprefix(char *commandname, char *pathvariables)
{
	char	**pathlist;
	int		count;
	char	*buffer;
	char	*buffer2;

	count = 0;
	pathlist = ft_split(pathvariables, ':');
	if (pathlist == NULL)
		return (commandname);
	buffer2 = ft_strjoin("/", commandname);
	while (pathlist[count] != NULL)
	{
		buffer = ft_strjoin(pathlist[count], buffer2);
		if (access(buffer, X_OK) == 0)
		{
			free(commandname);
			return (buffer);
		}
		free(buffer);
		++count;
	}
	free(buffer2);
	ft_clear_strarray(pathlist);
	return (commandname);
}
