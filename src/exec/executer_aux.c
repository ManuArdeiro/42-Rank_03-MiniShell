/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:57:23 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/03 17:41:44 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_directory(const char *path)
{
	struct stat	statbuf;
	int			status;

	status = FALSE;
	if (path == NULL)
		return (0);
	if (stat(path, &statbuf) != 0)
		return (0);
	status = S_ISDIR(statbuf.st_mode);
	return (status);
}

void	ft_terminateprocess(
	t_command *command, char **args, char **envp, const char *errortype
)
{
	ft_clear_strarray(envp);
	ft_clear_strarray(args);
	if (ft_strcontains(errortype, "in") == TRUE
		|| ft_strcontains(errortype, "out") == TRUE)
		ft_check_filepermissions(
			(t_file *)(command->infile->content),
			(t_file *)(command->outfile->content), errortype);
	else if (errortype != NULL)
		ft_print_commanderror(command->name, errortype);
	ft_free_commandlist(&command);
	if (ft_strequal(errortype, PERMISSION_DENIED) == TRUE
		|| ft_strequal(errortype, IS_DIRECTORY) == TRUE)
		exit(126);
	else
		exit(127);
}
