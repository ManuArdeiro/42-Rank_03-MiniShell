/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_completeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:08:48 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/17 19:53:18 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	ft_loop_end(const char *line, const char *prompt)
{
	if ((ft_strequal(prompt, PIPELINE) == TRUE
			&& ft_strlen(line) > 0 && line[0] != '\n')
		|| (ft_strequal(prompt, BACKSLASH) == TRUE
			&& line != NULL && line[0] != '\\'))
		return (TRUE);
	return (FALSE);
}

static char	*ft_completeline(const char *commandline, const char *prompt)
{
	char	*line;
	char	*buffer;
	char	*result;

	buffer = NULL;
	result = NULL;
	line = "";
	if (commandline == NULL || prompt == NULL)
		return (NULL);
	buffer = ft_strdup(commandline);
	while (line != NULL)
	{
		ft_putstr_fd(prompt, STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (line != NULL)
			buffer = ft_strjoin_get(buffer, line);
		if (ft_loop_end(line, prompt) == TRUE)
			break ;
		free(line);
	}
	result = ft_strclean_withspaces(buffer, CLEAN_ALL_LEAVE_PIPE);
	free(buffer);
	return (result);
}

static char	*ft_findsplitter(const char *commandline)
{
	char	*completeline;

	completeline = NULL;
	if (ft_endswith(commandline, "\\") == TRUE)
		completeline = ft_completeline(commandline, BACKSLASH);
	else if (ft_endswith(commandline, "|") == TRUE)
		completeline = ft_completeline(commandline, PIPELINE);
	return (completeline);
}

char	*ft_get_completeline(const char *commandline)
{
	char	*completeline;

	completeline = NULL;
	if (commandline == NULL)
		return (NULL);
	if (ft_countalpha(commandline) <= 1 && commandline[0] != '\\')
		return ((char *)commandline);
	completeline = ft_findsplitter(commandline);
	if (completeline && ft_endswith(completeline, "|") == TRUE)
		completeline = ft_get_completeline(completeline);
	if (completeline)
		free((char *)commandline);
	else
		return ((char *)commandline);
	return (completeline);
}

