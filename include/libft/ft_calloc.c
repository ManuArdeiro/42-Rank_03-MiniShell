/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:20:55 by jolopez-          #+#    #+#             */
/*   Updated: 2023/12/20 20:43:15 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (SIZE_MAX / size < count)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (!ptr)
	{
		return (NULL);
		free(ptr);
	}
	i = 0;
	while (i < (count * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
