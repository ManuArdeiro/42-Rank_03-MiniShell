/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_cmdtoken.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:31:55 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/30 20:05:37 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_cmdtoken(const char *line, t_part *tokens, int *i)
{
	if (ft_strchr("\'\"", line[*i + 1]) != NULL)
		ft_add_tkn(tokens, tk_cmd, *i, *i);
	else
		ft_add_tkn(tokens, tk_cmd, *i, *i + 1);
	(*i)++;
}
