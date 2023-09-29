/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniparser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:37:00 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/29 19:34:02 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_is_wildcard(t_token token)
{
	if (token == tk_pipe || token == tk_and || token == tk_mul
		|| token == tk_ampersand || token == tk_or)
		return (TRUE);
	return (FALSE);
}

t_minitree	*ft_parse_line(char *line, t_part *tokenlist, int token_count)
{
	t_minitree	*minitree;

	//IF command number > 1
	//Create tri_node
	while (count < token_count)
	{
		if (ft_is_wildcard(token_array[count]) == TRUE)
			ft_get_command(line, count);
		++count;
	}
	return (minitree);
}
