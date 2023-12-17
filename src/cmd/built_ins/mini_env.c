/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:38:09 by jolopez-          #+#    #+#             */
/*   Updated: 2023/12/16 18:14:26 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function prints all the key/values stored in the envList list.	*/

int	ft_mini_env(t_list *envList)
{
	t_list	*node;

	if (!envList)
		return (0);
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