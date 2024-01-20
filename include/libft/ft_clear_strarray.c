/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_strarray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:19:59 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/19 19:46:25 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clear_strarray(char **strarray)
{
	int	count;

	count = 0;
	if (!strarray || *strarray == NULL)
		return ;
	while (strarray[count])
	{
		if (strarray[count] != NULL && strarray[count][0] != '\0')
			free(strarray[count]);
		++count;
	}
	free(strarray);
}
