/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:49:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/21 19:27:44 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char	*ft_getenv(const char *key, t_list *envlist)
{
	t_list	*node;
	size_t	len;

	if (!key || envlist == NULL)
		return (NULL);
	len = ft_strlen(key);
	node = envlist;
	while (node != NULL)
	{
		printf("%s\n", (char*)(((t_dict *)node->content)->key));
		if (ft_strncmp(((t_dict *)node->content)->key, key, len) == 0)
			return (((t_dict *)node->content)->value);
		node = node->next;
	}
	return (NULL);
}
