/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:22:29 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/21 20:27:27 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Function to write a string (command) in the passed file descriptor and
	add a new line.	*/

static void	ft_write_command(const char *string, int file_descriptor)
{
	ft_putstr_fd(string, file_descriptor);
	ft_putstr_fd("\n", file_descriptor);
}

/*	This function cretes a new list item (wich contains the command) and
	adds it to the commands history.	*/

void	ft_register_command(t_list **history, char *command)
{
	t_list	*new;
	char	*buffer;

	if (command != NULL)
	{
		buffer = ft_strdup(command);
		new = ft_lstnew((char *)buffer);
		ft_lstadd_back(history, new);
	}
}

/*	This function open a file in path to write all the nodes in
	the list passed. If the open can't be openned it prints an error.

No entiendo la forma recursiva __func__	*/

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

/*	This function gets the path of HOME in the environment list and save
	(using ft_write_to_file()) the command history to a file called
	.minishell_history in the HOME directory.	*/

void	ft_write_command_history(t_list **history, t_global *global)
{
	char	*path;

	if (*history == NULL || history == NULL)
		return ;
	path = ft_getenv("HOME", global->envlist);
	if (path != NULL)
		path = ft_strjoin_get(path, "/.minishell_history");
	if (path != NULL)
		ft_write_to_file(history, path);
	free(path);
}
