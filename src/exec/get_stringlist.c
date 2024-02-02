/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stringlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:20:31 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/02 16:34:44 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_get_stringend(char *string, int start)
{
	int	i;

	i = start;
	if (string == NULL)
		return (0);
	while (string[i] != '\0' && string[i] != '$')
		i++;
	if (string[i] == '$' && ft_isalnum(string[i + 1]) == TRUE)
		i--;
	return (i);
}

static void	ft_add_tolist(t_list **list, char *delimiter)
{
	int	start;
	int	end;
	int	len;

	start = 0;
	end = 0;
	len = ft_strlen(delimiter);
	while (delimiter[start] != '\0')
	{
		if (delimiter[start] == '$')
		{
			if (ft_isalnum(delimiter[start + 1]) == TRUE
				|| delimiter[start + 1] == '?'
				|| delimiter[start + 1] == '\''
				|| delimiter[start + 1] == '\"')
				start++;
			end = ft_get_stringend(delimiter, start);
			ft_lstinsert(list,
				ft_substr(delimiter, start, end - start + 1), BACK);
			start = end;
		}
		if (start < len)
			start++;
	}
}

t_list	*ft_get_stringlist(const char *fullstring)
{
	t_list	*list;
	char	*delimiter;
	char	*stringstart;

	list = NULL;
	stringstart = NULL;
	if (fullstring == NULL)
		return (NULL);
	delimiter = ft_strchr(fullstring, '$');
	if (delimiter != NULL)
	{
		stringstart = ft_cutstr(fullstring, delimiter);
		if (stringstart != NULL && stringstart[0] != '\0')
			ft_lstinsert(&list, stringstart, FRONT);
		else
			free(stringstart);
		ft_add_tolist(&list, delimiter);
	}
	return (list);
}
