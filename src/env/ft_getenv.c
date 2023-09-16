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

int	ft_check_name_in_dict(t_list *envlist, const char *name)
{
	t_list	*node;
	size_t	len;

	if (!name || !envlist)
		return (FALSE);
	len = ft_strlen(name);
	node = envlist;
	while (node != NULL)
	{
		if (ft_strncmp(((t_dict *)node->content)->name, name, len) == 0)
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}

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

void	ft_cleardict(void *content)
{
	t_dict	*dict;

	if (content == NULL)
		return ;
	dict = (t_dict *)content;
	free(dict->name);
	free(dict->value);
}
