/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokenpair.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:29:13 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/18 12:29:56 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	ft_get_tokenpair(t_token token)
{
	if (token == tk_lprnths)
		return (tk_rprnths);
	if (token == tk_rprnths)
		return (tk_lprnths);
	return (token);
}
