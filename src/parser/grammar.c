/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:23:26 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/04 10:28:04 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
-> search for separator 
-> search for or / and
-> search for pipline
-> search for command
-> if (token == TRUE) lookahead ->
*/
t_bool	ft_looknext(t_minitree *node)
{
	if ((t_token)node->content == /*token*/)
	{
	}
	else
		ft_printerror(NULL, "Parser error");
	return (FALSE);
}
