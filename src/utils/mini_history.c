/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:22:29 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/12 20:57:35 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_init_history(void)
{
	int	file;

	file = open("minishell", );
	return (file);
}

void	ft_close_history(t_history **history, int fd)
{
	if (close(fd) < 0)
		ft_printerror(__func__, "Close");
}

static void	ft_write_command(char *string, int file_descriptor)
{
	ft_putstr_fd(string, file_descriptor);
	ft_putstr_fd("\n", file_descriptor);
}

void	ft_register_command(t_history *history, char *command)
{
	
}

void	ft_write_command_history(t_history *history)
{
	
}