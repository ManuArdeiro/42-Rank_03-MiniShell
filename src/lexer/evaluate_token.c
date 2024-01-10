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

static void	subadd_quotes(t_part *tokens, char *line, int *i, int *ok)
{
	if (line[*i] == '\'')
	{
		if (line[*i + 1] != ' '
			&& ft_strchr("()\'\";*<>|&", line[*i + 1]) == NULL)
			*ok = ft_add_tkn(tokens, tk_sglquot, *i, *i + 1);
		else
			*ok = ft_add_tkn(tokens, tk_sglquot, *i, *i);
	}
	else if (line[*i] == '\"')
	{
		if (line[*i + 1] != ' '
			&& ft_strchr("()\'\";*<>|&", line[*i + 1]) == NULL)
			*ok = ft_add_tkn(tokens, tk_dblquot, *i, *i + 1);
		else
			*ok = ft_add_tkn(tokens, tk_dblquot, *i, *i);
	}
}

void	ft_evaluatetoken(t_part *tokens, char *line, int *i, int *ok)
{
	if (ok != (int *)0)
		subadd_quotes(tokens, line, i, ok);
	else
	{
		if (line[*i + 1] == ' ')
			ft_add_tkn(tokens, tk_cmd, *i, *i);
		else
			ft_add_tkn(tokens, tk_cmd, *i, *i + 1);
	}
	*i = *i + 1;
}
