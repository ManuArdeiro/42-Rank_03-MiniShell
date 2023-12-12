/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_completeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:08:48 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/12 19:15:22 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_getline_aux(const char *buffer, const char *prompt)
{
	char	*result;

	result = NULL;
	if (buffer == NULL)
		return (NULL);
	if (ft_endswith(buffer, "\\\n") == FALSE)
	{
		if (ft_strequal(prompt, "pipe $> ") == TRUE)
			result = ft_strclean_withspaces(buffer, CLEAN_ALL_LEAVE_PIPE);
		else
			result = ft_strclean_withspaces(buffer, CLEAN_ALL);
	}
	return (result);
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
		free(line);
		result = ft_getline_aux(buffer, prompt);
		if (result != NULL)
			break ;
	}
	free(buffer);
	return (result);
}

static char	*ft_findsplitter(const char *commandline)
{
	char	*delimiter;
	char	*completeline;

	completeline = NULL;
	delimiter = ft_strrchr(commandline, '\\');
	if (delimiter != NULL)
	{
		if (*(delimiter + 1) != '\0')
			completeline = ft_strstrip(commandline);
		else
			completeline = ft_completeline(commandline, BACKSLASH);
	}
	else if (delimiter == NULL)
	{
		delimiter = ft_strrchr(commandline, '|');
		if (delimiter != NULL)
		{
			if (ft_countalpha(delimiter) == 0)
				completeline = ft_completeline(commandline, PIPELINE);
		}
	}
	return (completeline);
}

char	*ft_get_completeline(const char *commandline)
{
	char	*completeline;

	completeline = NULL;
	if (commandline == NULL)
		return (NULL);
	completeline = ft_findsplitter(commandline);
	if (completeline)
		free((char *)commandline);
	else
		return ((char *)commandline);
	return (completeline);
}
