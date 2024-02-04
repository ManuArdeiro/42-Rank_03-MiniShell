/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_backslash_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:32:51 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/04 11:33:58 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_is_backslash_token(t_token token)
{
	if (token == tk_slash_sglquot || token == tk_slash_dblquot)
		return (TRUE);
	return (FALSE);
}
