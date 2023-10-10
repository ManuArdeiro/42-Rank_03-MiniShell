/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:37:04 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/04 11:08:18 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniparser.h"

int	ft_get_tokencount(t_list *summary, t_token token)
{
	int		result;
	t_list	*node;

	if (!summary || !token)
		return (0);
	node = summary;
	result = 0;
	while (node != NULL)
	{
		if (((t_summarizer *)node->content)->token == token)
			result = ((t_summarizer *)node->content)->count;
		node = node->next;
	}
	return (result);
}
