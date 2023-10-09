/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:23:35 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/08 15:25:49 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_mini_unset(t_list *envList, char **args)
{
	int	i;
	int	nbr;

	i = 0;
	while (args[i] != NULL)
	{
		nb = get_env_var_nb(tcsh->env.env, cmd->cmd[i]);
		if (nb != -1)
			tcsh->env.env = ft_arrdelline(tcsh->env.env, (size_t)nb);
		i++;
	}
	if (i < 2)
	{
		ft_putendl_fd("unsetenv: Too few arguments.", 2);
		return (1);
	}
	return (0);
}
