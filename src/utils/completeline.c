/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:11:14 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/22 18:26:08 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	ft_loop_end(const char *line, const char *prompt)
{
	if ((ft_strequal(prompt, PIPELINE) == TRUE
			&& ft_strlen(line) > 0 && line[0] != '\n' && line[0] != '|')
		|| (ft_strequal(prompt, BACKSLASH) == TRUE
			&& line != NULL && line[0] != '\\'))
		return (TRUE);
	return (FALSE);
}

static char	*ft_gnl_loop(
	const char *commandline, const char *prompt, int pip[2])
{
	char	*buffer;
	char	*line;

	buffer = ft_strdup(commandline);
	line = "";
	while (line != NULL)
	{
		ft_putstr_fd(prompt, STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
		{
			ft_closepipe(&pip[0], &pip[1]);
			ft_printerror(__func__, "Get next line");
			exit(EXIT_FAILURE);
		}
		else
			buffer = ft_strjoin_get(buffer, line);
		if (ft_loop_end(line, prompt) == TRUE)
			break ;
		free(line);
	}
	return (buffer);
}

char	*ft_completeline(
		const char *commandline, const char *prompt, int pip[2])
{
	char	*buffer;
	char	*result;

	result = NULL;
	if (commandline == NULL || prompt == NULL)
		return (NULL);
	buffer = ft_gnl_loop(commandline, prompt, pip);
	if (ft_endswith(buffer, "\\") == TRUE)
		result = ft_strclean_withspaces(buffer, CLEAN_ALL);
	else
		result = ft_strclean_withspaces(buffer, CLEAN_ALL_LEAVE_PIPE);
	free(buffer);
	return (result);
}
