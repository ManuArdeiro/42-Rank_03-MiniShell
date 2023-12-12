/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclean_withspaces.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:26:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/12 19:09:01 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_validate_chr(int chr, int cleanoption)
{
	if (cleanoption == 0
		&& (ft_isalpha(chr) != 0 || chr == ' ' || chr == '|'))
		return (1);
	else if (cleanoption == 1 && (ft_isalpha(chr) != 0 || chr == ' '))
		return (1);
	else if (cleanoption == 2 && (chr != '\'' && chr != '\"'))
		return (1);
	else if (cleanoption == 3 && chr != '\'')
		return (1);
	else if (cleanoption == 4 && chr != '\"')
		return (1);
	return (0);
}

static void	ft_get_cleanstring(
		char **cleanstring, const char *string, int cleanoption)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (string[i] != '\0')
	{
		if (ft_validate_chr(string[i], cleanoption) == 1)
		{
			(*cleanstring)[count] = string[i];
			++count;
		}
		++i;
	}
	(*cleanstring)[count] = '\0';
}

static int	ft_countalpha_withspace(const char *string, int cleanoption)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (string[i] != '\0')
	{
		if (ft_validate_chr(string[i], cleanoption) == 1)
			++count;
		++i;
	}
	return (count);
}

char	*ft_strclean_withspaces(const char *string, int cleanoption)
{
	char	*cleanstr;
	int		len;

	cleanstr = NULL;
	if (string == NULL)
		return (NULL);
	len = ft_countalpha_withspace(string, cleanoption);
	cleanstr = malloc(sizeof(char) * (len + 1));
	if (cleanstr == NULL)
		return (NULL);
	ft_get_cleanstring(&cleanstr, string, cleanoption);
	return (cleanstr);
}
