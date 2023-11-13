/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:50:18 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/13 20:03:26 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_isbuiltin(char *commandname)
{
	if (commandname == NULL)
		return (EXITED);
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
	else if (ft_strequal(commandname, "clear") == TRUE)
		return (TRUE);
	return (FALSE);
}
