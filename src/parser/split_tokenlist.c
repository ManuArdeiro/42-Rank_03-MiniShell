/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tokenlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:52:43 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/10 19:07:19 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minitree	*ft_split_tokenlist(t_part *tokenlist)
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
				break ;
		}
		++token;
	}
	return (newnode);
}
