/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:36:29 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/21 19:30:33 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_printenv(t_list *envlist)
{
	t_list	*node;
	int		count;

	if (!envlist)
		return (0);
	count = 0;
	node = envlist;
	while (node != NULL)
	{
		printf("%s ", ((t_dict *)node->content)->key);
		printf("= %s\n", ((t_dict *)node->content)->value);
		++count;
		node = node->next;
	}
	return (count);
}
