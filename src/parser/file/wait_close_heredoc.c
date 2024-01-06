/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_close_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:27:11 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/06 21:20:55 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_wait_close_heredoc(pid_t child, t_file *file, int *herepipe, t_global *global)
{
	int		status;

	status = EXIT_SUCCESS;
	file->fd = dup(herepipe[0]);
	ft_closepipe(&herepipe[0], &herepipe[1]);
	waitpid(child, &status, EXIT_SUCCESS);
	ft_evaluate_subprocess(status, global);
}
