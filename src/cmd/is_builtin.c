/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:50:18 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/21 18:45:40 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_isbuiltin(char *commandname)
{
	printf("commandname = %s\n", commandname);
	if (commandname == NULL)
		return (EXITED);
	else if (ft_strequal(commandname, "ls") == TRUE)
		return (TRUE);
	else if (ft_strequal(commandname, "echo") == TRUE)
		return (TRUE);
	else if (ft_strequal(commandname, "unset") == TRUE)
		return (TRUE);
	else if (ft_strequal(commandname, "pwd") == TRUE)
		return (TRUE);
	else if (ft_strequal(commandname, "cd") == TRUE)
		return (TRUE);
	else if (ft_strequal(commandname, "env") == TRUE)
		return (TRUE);
	else if (ft_strequal(commandname, "export") == TRUE)
		return (TRUE);
	else if (ft_strequal(commandname, "exit") == TRUE)
		return (TRUE);
	return (FALSE);
}
