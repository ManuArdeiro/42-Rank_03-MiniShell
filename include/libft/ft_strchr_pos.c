/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:54:12 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/15 20:03:55 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_pos(const char *s, int c, int pos)
{
	int	i;
	int	charcount;

	i = 0;
	charcount = 0;
	if (!s || pos < 0)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			charcount++;
		if (s[i] == (char)c && pos == 0)
			return ((char *)(s + i));
		else if (s[i] == (char)c && pos == charcount)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}