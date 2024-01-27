/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequal_cs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:58:37 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/27 19:00:47 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifndef TRUE
# define TRUE 1
#endif
#ifndef FALSE
# define FALSE 0
#endif

int	ft_strequal_cs(const char *str1, const char *str2)
{
	char	*string1;
	char	*string2;
	int		len1;
	int		len2;
	int		result;

	if (str1 == NULL || str2 == NULL)
		return (FALSE);
	result = FALSE;
	string1 = ft_strdup(str1);
	string2 = ft_strdup(str2);
	len1 = ft_strlen(string1);
	len2 = ft_strlen(string2);
	if (len2 > len1)
		result = ft_strncmp(string1, string2, len2);
	else
		result = ft_strncmp(string1, string2, len1);
	free(string1);
	free(string2);
	if (result == 0)
		return (TRUE);
	else
		return (FALSE);
}
