/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tokenlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:52:43 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/25 17:35:27 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_split_tokenlist(t_minitree **root, t_part *tokenlist)
{
	t_token		token;
	t_minitree	*newnode;

	token = 0;
	newnode = NULL;
	while (token < max_token)
	{
		if (ft_is_tokenseparator(token) == TRUE)
		{
			newnode = ft_tokensplit(tokenlist, token);
			if (newnode != NULL)
			{
				if (ft_is_emptynode(*root) == FALSE)
					ft_destroytree(root, ft_free_mininode);
				*root = newnode;
				break ;
			}
		}
		++token;
	}
}
