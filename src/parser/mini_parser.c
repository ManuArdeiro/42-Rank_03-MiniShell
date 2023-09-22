/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:37:00 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/22 20:12:11 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniparser.h"

t_command	*ft_parse_line(t_token *tokens_array)
{
	t_command	*commands;
	int			commands_count;

	commands_count = ft_sum;//count commands
	//count args
	//count wildcards
	commands = malloc(sizeof(t_command) * commands_count);
	if (!commands)
		return (NULL);
	return (commands);
}
