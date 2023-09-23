/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:37:00 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/23 20:19:32 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniparser.h"

t_command	*ft_parse_line(t_token *tokens_array, int token_count)
{
	t_list		*command_summary;
	//t_command	*commands;
	//int			commands_count;

	if (!tokens_array || token_count <= 0)
		return (NULL);
	command_summary = ft_summarize(tokens_array, token_count);
	ft_printsummary(command_summary);
	ft_lstclear(&command_summary, free);
	//find commands
	//commands_count = 0;
	//commands = malloc(sizeof(t_command) * commands_count);
	//if (!commands)
	//	return (NULL);
	//return (commands);
	return (NULL);
}