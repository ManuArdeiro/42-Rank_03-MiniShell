/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:29:06 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/10 14:32:51 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_substr(
	const char *commandline, t_part *secondnode, t_part *node)
{
	char	*buffer;

	buffer = NULL;
	if (secondnode != NULL && secondnode->end >= node->start)
	{
		buffer = ft_substr(commandline, node->start,
				((secondnode->end) - (node->start) + 1));
	}
	else if (secondnode == NULL)
	{
		secondnode = ft_get_lasttoken(node);
		if (secondnode != NULL)
			buffer
				= ft_substr(commandline, node->start,
					((secondnode->end) - (node->start) + 1));
	}
	return (buffer);
}

char	*ft_expandstring(
	t_global *global,
	t_part *startnode, t_part *endnode, t_cleancase cleancase)
{
	char	*expandedstring;
	char	*substring;
	char	*buffer;

	expandedstring = NULL;
	substring = ft_get_substr(global->line, endnode, startnode);
	buffer = ft_strclean_withspaces(substring, cleancase);
	if (ft_strcontains(buffer, "$") == TRUE
		&& global->expand_dollartoken == TRUE && global->fileflag == FALSE)
		expandedstring = ft_expand_dollartoken(buffer, global);
	else
		expandedstring = ft_strdup(buffer);
	if (buffer != NULL)
		free(buffer);
	if (substring != NULL)
		free(substring);
	return (expandedstring);
}
