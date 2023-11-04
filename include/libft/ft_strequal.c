/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:26:26 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/03 20:42:01 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifndef TRUE
# define TRUE 1
#endif
#ifndef FALSE
# define FALSE 0
#endif

static int	ft_isupper(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (TRUE);
	return (FALSE);
}

static char	*ft_strlower(char *string)
{
	char	ch;
	int		i;

	if (!string)
		return (NULL);
	i = 0;
	while (string[i] != '\0')
	{
		ch = string[i];
		if (ft_isupper(ch) == TRUE)
		{
			ch = ft_tolower(ch);
			string[i] = ch;
		}
		i++;
	}
	return (string);
}

int	ft_strequal(const char *str1, const char *str2)
{
	char	*string1;
	char	*string2;
	int		len;
	int		result;

	if (str1 == NULL || str2 == NULL)
		return (FALSE);
	result = FALSE;
	string1 = ft_strdup(str1);
	string2 = ft_strdup(str2);
	ft_strlower(string1);
	ft_strlower(string2);
	len = ft_strlen(string1);
	result = ft_strncmp(string1, string2, len);
	free(string1);
	free(string2);
	if (result == 0)
		return (TRUE);
	else
		return (FALSE);
}
