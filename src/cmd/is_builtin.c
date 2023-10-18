/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:50:18 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/18 18:04:28 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_isbuiltin(char *commandname)
{
	if (commandname == NULL)
		return (EXITED);
	else if (ft_strncmp(commandname, "ls", 2) == 0)
		return (TRUE);
	else if (ft_strncmp(commandname, "echo", 4) == 0)
		return (TRUE);
	else if (ft_strncmp(commandname, "unset", 5) == 0)
		return (TRUE);
	else if (ft_strncmp(commandname, "pwd", 3) == 0)
		return (TRUE);
	else if (ft_strncmp(commandname, "cd", 2) == 0)
		return (TRUE);
	else if (ft_strncmp(commandname, "env", 3) == 0)
		return (TRUE);
	else if (ft_strncmp(commandname, "export", 6) == 0)
		return (TRUE);
	else if (ft_strncmp(commandname, "exit", 4) == 0)
		return (TRUE);
	return (FALSE);
}
