/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:38:09 by jolopez-          #+#    #+#             */
/*   Updated: 2024/01/24 18:43:31 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function prints all the key/values stored in the envList list.	*/

int	ft_mini_env(t_list *envList, char **args)
{
	t_list	*node;

	if (!envList)
		return (EXIT_FAILURE);
	if (args != NULL && args[0])
	node = envList;
	while (node)
	{
		ft_putstr_fd(((t_dict *)node->content)->key, STDOUT_FILENO);
		ft_putstr_fd("=", STDOUT_FILENO);
		ft_putendl_fd(((t_dict *)node->content)->value, STDOUT_FILENO);
		node = node->next;
	}
	return (EXIT_SUCCESS);
}
