/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_last_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:20:09 by jolopez-          #+#    #+#             */
/*   Updated: 2023/12/18 21:01:12 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_del_last_tkn(t_part *tokens)
{
	int		move;
	t_part	*antelast_tk;

	move = 0;
	antelast_tk = tokens;
	while (antelast_tk->next != NULL)
	{
		move = 0;
		if (antelast_tk->next->next)
		{
			antelast_tk = antelast_tk->next;
			move = 1;
		}
		else if (move == 0)
		{
			free(antelast_tk->next);
			antelast_tk->next = NULL;
		}
	}
	return ;
}
