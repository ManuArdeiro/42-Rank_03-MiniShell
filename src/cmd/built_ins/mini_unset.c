/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:23:35 by jolopez-          #+#    #+#             */
/*   Updated: 2023/11/23 21:13:15 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_unset_var(t_list *envList, char **args)
{
	int		i;
	char	*env_value;

	i = 1;
	while (args[i] != NULL)
	{
		env_value = ft_getenv(args[i], envList);
		if (env_value != NULL)
		{
			if (ft_delenv(envList, args[i]))
			{
				ft_putstr_fd("unset: error unsetting ", STDERR_FILENO);
				ft_putstr_fd(args[1], STDERR_FILENO);
				ft_putendl_fd(" variable.", STDERR_FILENO);
				return (EXIT_FAILURE);
			}
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_mini_unset(t_list *envList, char **args)
{
	if (ft_arg_nbr(args) < 2)
	{
		ft_putendl_fd("unset: not enough arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (ft_unset_var(envList, args));
}
