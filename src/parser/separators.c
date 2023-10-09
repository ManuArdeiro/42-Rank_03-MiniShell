/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:58:37 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/09 15:55:57 by yzaytoun         ###   ########.fr       */
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

t_bool	ft_is_logicalseparator(t_token token)
{
	if (token == tk_and || token == tk_or)
		return (TRUE);
	return (FALSE);
}

t_bool	ft_is_pipeseparator(t_token token)
{
	if (token == tk_pipe)
		return (TRUE);
	return (FALSE);
}

t_bool	ft_is_subshellseparator(t_token token)
{
	if (token == tk_lprnths)
		return (TRUE);
	return (FALSE);
}
