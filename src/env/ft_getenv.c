/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:49:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/23 21:05:56 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function looks for the passed key in the environment list and if it
	is found, then returns the string of the assciated value (path).

Por qué lo escribes así?	*/
char	*ft_getenv(const char *key, t_list *envlist)
{
	t_list	*node;
	char	*result;

	if (!key || envlist == NULL)
		return (NULL);
	node = envlist;
	while (node != NULL)
	{
		if (ft_strequal(((t_dict *)node->content)->key, key) == TRUE)
		{
			result = ft_strdup(((t_dict *)node->content)->value);
			return (result);
		}
		node = node->next;
	}
	return (NULL);
}
