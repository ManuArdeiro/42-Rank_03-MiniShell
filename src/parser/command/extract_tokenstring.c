/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_tokenstring.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:50:43 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/01 20:15:32 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_extract_tokenstring(const char *commandline, t_part *node)
{
	char	*value;

	if (node == NULL || commandline == NULL)
		return (NULL);
	value = NULL;
	value = ft_substr(commandline, node->start, (node->end - node->start) + 1);
	return (value);
}

