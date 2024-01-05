/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkquotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:54:23 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/05 17:56:38 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_checkquotes(char **string)
{
	char	*buffer;

	buffer = (*string);
	if (ft_strchr(buffer, '\'') != NULL
		|| ft_strchr(buffer, '\"') != NULL)
	{
		(*string) = ft_strclean_withspaces(buffer, CLEAN_ALL);
		if (buffer != NULL)
			free(buffer);
	}
}
