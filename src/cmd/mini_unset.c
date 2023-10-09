/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:23:35 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/09 18:39:53 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_mini_unset(t_list *envList, char **args)
{
	int		i;
	char	*env_value;

	i = 0;
	if (ft_arg_nbr(args) < 1)
	{
		ft_putendl_fd("unset: at least one argument is needed.", STDOUT_FILENO);
		ft_putendl_fd("unset: at least one argument is needed.", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	while (args[i] != NULL)
	{
		env_value = ft_getenv(envList, args[i]);
		if (env_value != NULL)
		{
			if (ft_delenv(envList, args[i]))
			{
				printf("unset: error  unsetting %s variable.", args[i]);
				return (EXIT_FAILURE);
			}
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
