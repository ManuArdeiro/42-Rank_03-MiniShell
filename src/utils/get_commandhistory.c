/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commandhistory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:50:54 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/28 11:43:11 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//FIXME - Clean text from new line
static void	ft_add_commandhistory(int file_descriptor)
{
	char	*line;

	line = "";
	while (line != NULL)
	{
		line = get_next_line(file_descriptor);
		if (line != NULL)
			add_history(line);
		free(line);
	}
}

void	ft_get_commandhistory(t_list *envlist)
{
	char	*minishell_history;
	int		file_descriptor;

	if (envlist == NULL)
		return ;
	minishell_history = ft_getenv("HOME", envlist);
	if (minishell_history == NULL)
		return ;
	minishell_history
		= ft_strjoin_get(minishell_history, "/.minishell_history");
	if (minishell_history == NULL)
		return ;
	file_descriptor = open(minishell_history, O_RDONLY);
	if (file_descriptor < 0)
		return ;
	ft_add_commandhistory(file_descriptor);
	free(minishell_history);
	close(file_descriptor);
}
