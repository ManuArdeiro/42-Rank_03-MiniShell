/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_completeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:08:48 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/18 18:49:34 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_cleanstring(char *string)
{
	int		count;
	int		len;
	char	*dest;

	dest = NULL;
	if (string == NULL)
		return (NULL);
	len = ft_strlen(string);
	dest = malloc(sizeof(char) * len);
	if (dest == NULL)
		return (NULL);
	count = 0;
	while (string[count] != '\0' && count < len - 1)
	{
		dest[count] = string[count];
		++count;
	}
	dest[len - 1] = '\0';
	free(string);
	return (dest);
}

//FIXME -> Cleantext with space
static char	*ft_completeline(const char *commandline, const char *prompt)
{
	char	*line;
	char	*buffer;

	buffer = NULL;
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
		if (ft_endswith(buffer, "\\") == FALSE)
		{
			if (ft_startswith(prompt, "pipe") == TRUE)
				buffer = ft_cleanstring(buffer);
			break ;
		}
	}
	return (buffer);
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
