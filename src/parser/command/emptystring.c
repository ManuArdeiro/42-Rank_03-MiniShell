/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emptystring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:53:20 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/02 18:54:17 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_emptystring(const char *string)
{
	if (string == NULL || string[0] == '\0')
		return (TRUE);
	return (FALSE);
}
