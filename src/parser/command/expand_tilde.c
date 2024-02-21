/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tilde.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:09:02 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/21 20:28:19 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_expandtilde(char *string, t_list *envlist)
{
	char	*expandedstring;
	char	*homepath;
	char	*buffer;

	homepath = NULL;
	if (string == NULL)
		return (NULL);
	buffer = string;
	expandedstring = NULL;
	homepath = ft_getenv("HOME", envlist);
	if (homepath != NULL)
	{
		buffer++;
		expandedstring = ft_strjoin(homepath, buffer);
		free(homepath);
	}
	if (expandedstring == NULL)
		return ((char *)string);
	else
		free(string);
	return (expandedstring);
}
