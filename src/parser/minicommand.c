/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minicommand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:25:34 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/26 20:41:33 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*ft_createcommand(char *name, char *arg, int infile, int outfile)
{
	t_command	*command;

	if (name == NULL || arg == NULL || infile < 0 || outfile < 0)
		return (NULL);
	command = malloc(sizeof(t_command));
	if (!command)
		return (NULL);
	command->name = ft_strdup(name);
	command->args = ft_split(arg, ' ');
	command->infile = infile;
	command->outfile = outfile;
	return (command);
}
