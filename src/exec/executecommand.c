/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executecommand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:44:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/25 18:20:13 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_executecommand(t_command *command, t_global *global)
{
	pid_t	*pidarray;
	int		pidcount;
	int		laststatus;
	char	*dollar_expansion;

	laststatus = global->laststatus;
	global->laststatus = EXIT_SUCCESS;
	pidarray = NULL;
	dollar_expansion = NULL;
	if (command == NULL)
		return ;
	ft_printcommand(command);
	dollar_expansion
		= ft_expand_dollartoken(command->name, global->envlist, laststatus);
	if (dollar_expansion != NULL)
		ft_lstinsert(&command->args, (char *)dollar_expansion, BACK);
	pidcount = ft_create_subprocess(command, &pidarray, global);
	global->laststatus = ft_wait_subprocess(pidarray, pidcount);
}
