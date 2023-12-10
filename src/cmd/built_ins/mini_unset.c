/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:23:35 by jolopez-          #+#    #+#             */
/*   Updated: 2023/12/10 14:33:34 by jolopez-         ###   ########.fr       */
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
		return (EXIT_SUCCESS);
	return (ft_unset_var(envList, args));
}
