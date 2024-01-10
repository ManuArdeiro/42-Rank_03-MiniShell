/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:10:00 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/10 19:13:12 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_evaluatetoken(t_part *tokens, char *line, int *i, int *ok)
{
	if (line[*i] == '\'')
	{
		if (line[*i + 1] != ' ')
			*ok = ft_add_tkn(tokens, tk_sglquot, *i, *i + 1);
		else
			*ok = ft_add_tkn(tokens, tk_sglquot, *i, *i);
	}
	else if (line[*i] == '\"')
	{
		if (line[*i + 1] != ' ')
			*ok = ft_add_tkn(tokens, tk_dblquot, *i, *i + 1);
		else
			*ok = ft_add_tkn(tokens, tk_dblquot, *i, *i);
	}
	*i = *i + 1;
}
