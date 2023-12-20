/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_tokenstring.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:50:43 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/20 19:04:00 by yzaytoun         ###   ########.fr       */
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
