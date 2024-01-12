/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_commandseries.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:29:13 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/12 17:22:26 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_extract_commandseries(
	const char *commandline,
	t_part *tokenlist, t_part **nextstart, t_global *global)
{
	t_part	*secondnode;
	char	*commandseries;

	commandseries = NULL;
	secondnode = NULL;
	if (commandline == NULL || tokenlist == NULL || global == NULL)
		return (NULL);
	secondnode = ft_get_last_seriestoken(tokenlist);
	commandseries
		= ft_get_commandseries(commandline, tokenlist, secondnode, global);
	if (nextstart != NULL)
		(*nextstart) = secondnode;
	return (commandseries);
}
