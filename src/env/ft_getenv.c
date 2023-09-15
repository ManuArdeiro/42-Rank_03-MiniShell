/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:49:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/15 18:23:24 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_name_in_dict(t_list *envlist, const char *name)
{
	t_list	*node;

	node = envlist;
	while (node != NULL)
	{
		if (ft_strcmp(((t_dict *)node->content)->name, name) == 0)
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}

char	*ft_getenv(t_list *envlist, const char *name)
{
	t_list	*node;

	node = envlist;
	while (node != NULL)
	{
		if (ft_strcmp(((t_dict *)node->content)->name, name) == 0)
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
