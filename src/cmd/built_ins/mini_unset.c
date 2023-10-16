/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:23:35 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/14 20:02:32 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	ft_unset_var(t_list *envList, char **args)
{
	int		i;
	char	*env_value;

	i = 0;
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
	int		i;
	char	*env_value;

	i = 0;
	if (ft_arg_nbr(args) < 1)
	{
		ft_putendl_fd("unset: at least one argument is needed.", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (ft_unset_var(envList, args));
}
