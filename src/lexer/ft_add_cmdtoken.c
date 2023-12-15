/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_cmdtoken.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:31:55 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/11 20:26:22 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_cmdtoken(const char *line, t_part *tokens, int *i)
{
	(void)line;
	if (ft_strchr("\'\"", line[*i + 1]) != NULL)
		ft_add_tkn(tokens, tk_cmd, *i, *i);
	else
		ft_add_tkn(tokens, tk_cmd, *i, *i + 1);
	(*i)++;
}
