/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:48:10 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/30 15:48:49 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_isseparator(t_token token)
{
	if (token == tk_pipe || token == tk_and || token == tk_mul
		|| token == tk_ampersand || token == tk_or)
		return (TRUE);
	return (FALSE);
}
