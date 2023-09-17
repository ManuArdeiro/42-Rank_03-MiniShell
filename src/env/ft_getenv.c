/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:49:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/16 18:50:01 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char	*ft_getenv(const char *name, t_list *envlist)
{
	t_list	*node;
	size_t	len;

	if (!name || !envlist)
		return (NULL);
	len = ft_strlen(name);
	node = envlist;
	while (node != NULL)
	{
		if (ft_strncmp(((t_dict *)node->content)->name, name, len) == 0)
			return (((t_dict *)node->content)->value);
		node = node->next;
	}
	return (NULL);
}