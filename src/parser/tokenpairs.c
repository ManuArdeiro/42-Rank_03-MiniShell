/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenpairs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:45:12 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/06 13:43:20 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_is_tokenpair(t_token token)
{
	if (token == tk_dblquot || token == tk_sglquot)
		return (TRUE);
	return (FALSE);
}
