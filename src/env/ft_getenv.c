/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:49:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/18 19:51:53 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char	*ft_getenv(const char *value, t_list *envlist)
{
	t_list	*node;
	size_t	len;

	if (!value || !envlist)
		return (NULL);
	len = ft_strlen(value);
	node = envlist;
	while (node != NULL)
	{
		if (ft_strncmp(((t_dict *)node->content)->value, value, len) == 0)
			return (((t_dict *)node->content)->value);
		node = node->next;
	}
	return (NULL);
}