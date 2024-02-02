/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stringpart.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:22 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/02 16:26:57 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_get_stringpart(const char *pathsuffix)
{
	t_bool	stringpart;

	stringpart = FALSE;
	if (pathsuffix == NULL)
		return (FALSE);
	if (ft_startswith(pathsuffix, "*") == TRUE)
		stringpart = FIRST;
	else
		stringpart = LAST;
	return (stringpart);
}
