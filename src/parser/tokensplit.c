/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokensplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:52:43 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/10 11:43:08 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_tokensplit(
	t_minitree **parsetree, t_part *tokenlist, t_token token)
{
	t_part	*node;
	t_part	*delimiter;

	if (tokenlist == NULL || token <= 0)
		return (NULL);
	node = tokenlist;
	while (node != NULL)
	{
		delimiter = ft_get_tokennode(node, token);
		ft_treeinsert(
			parsetree,
			ft_get_commandlist(tokenlist, delimiter),
			separator,
			ft_get_commandlist(tokenlist, delimiter)
		);
		node = node->next;
	}
}
