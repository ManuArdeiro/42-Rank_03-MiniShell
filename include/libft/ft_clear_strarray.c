/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_strarray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:19:59 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/15 19:21:24 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clear_strarray(char **strarray)
{
	if (*strarray == NULL || !strarray)
		return ;
	while (*strarray)
	{
		free(*strarray);
		++strarray;
	}
	free(strarray);
}
