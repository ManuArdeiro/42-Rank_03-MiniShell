/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:36:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/15 17:38:36 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_is_redirection(t_token token)
{
	if (token == tk_less || token == tk_dblless || token == tk_grt
		|| token == tk_dblgrt)
		return (TRUE);
	return (FALSE);
}
