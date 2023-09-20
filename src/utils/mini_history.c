/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:22:29 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/20 18:42:34 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_write_command(const char *string, int file_descriptor)
{
	ft_putstr_fd(string, file_descriptor);
	ft_putstr_fd("\n", file_descriptor);
}

void	ft_register_command(t_list **history, char *command)
{
	t_list	*new;

	new = ft_lstnew((char *)command);
	ft_lstadd_back(history, new);
}

void	ft_write_to_file(t_list **list, char *path)
{
	t_list	*node;
	int		file;

	node = *list;
	file = open(path, O_RDWR | O_CREAT | O_APPEND, 0664);
	if (file < 0)
	{
		ft_printerror(__func__, "History File");
		return ;
	}
	while (node != NULL)
	{
		ft_write_command((char *)node->content, file);
		node = node->next;
	}
	close(file);
}

void	ft_write_command_history(t_list **history, t_global *global)
{
	char	*path;

	if (*history == NULL || history == NULL)
		return ;
	path = ft_getenv("HOME", global->envlist);
	path = ft_strjoin_get(path, "/.minishell_history");
	if (path != NULL)
		ft_write_to_file(history, path);
}
