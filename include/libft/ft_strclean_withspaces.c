/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclean_withspaces.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:26:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/11 20:06:26 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_case(const char *string, int i, int stringcase)
{
	if (stringcase == 0)
	{
		if (ft_isalpha(string[i]) != 0
			|| string[i] == ' ' || string[i] == '|')
			return (1);
	}
	else if (stringcase == 1)
	{
		if (ft_isalpha(string[i]) != 0 || string[i] == ' ')
			return (1);
	}
	return (0);
}

static void	ft_get_cleanstring(
		char **cleanstring, const char *string, int skip_pipe)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (string[i] != '\0')
	{
		if (skip_pipe == 0 && ft_case(string, i, 0) == 1)
		{
			(*cleanstring)[count] = string[i];
			++count;
		}
		else if (skip_pipe == 1 && ft_case(string, i, 1) == 1)
		{
			(*cleanstring)[count] = string[i];
			++count;
		}
		else if (skip_pipe == 3 && string[i] != '\'' && string[i] != '\"')
		{
			(*cleanstring)[count] = string[i];
			++count;
		}
		++i;
	}
	(*cleanstring)[count] = '\0';
}

static int	ft_countalpha_withspace(const char *string, int skip_pipe)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (string[i] != '\0')
	{
		if (skip_pipe == 0
			&& (ft_isalpha(string[i]) != 0
				|| string[i] == ' ' || string[i] == '|'))
			++count;
		else if (skip_pipe == 1
			&& (ft_isalpha(string[i]) != 0 || string[i] == ' '))
			++count;
		else if (skip_pipe == 3
			&& (string[i] != '\'' && string[i] != '\"'))
			++count;
		++i;
	}
	return (count);
}

char	*ft_strclean_withspaces(const char *string, int skip_pipe)
{
	char	*cleanstr;
	int		len;

	cleanstr = NULL;
	if (string == NULL)
		return (NULL);
	len = ft_countalpha_withspace(string, skip_pipe);
	cleanstr = malloc(sizeof(char) * (len + 1));
	if (cleanstr == NULL)
		return (NULL);
	ft_get_cleanstring(&cleanstr, string, skip_pipe);
	return (cleanstr);
}
