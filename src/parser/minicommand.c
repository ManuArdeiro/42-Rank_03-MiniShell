/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minicommand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:25:34 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/27 18:35:46 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//FIXME - Need to manage null not to avoid it
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

t_minitree	*ft_create_commandnode(char *line, t_token wildcard)
{
	t_minitree	*minitree;

	//Extract commands
	ft_createcommand(
		ft_substr(line, token->start, token->end)
		ft_substr(line, token->start, token->end),
		//if redirection count > command
		//if redirection count < command
		//Else default
		);
	minitree = ft_create_treenode(void *)(uintptr_t)wildcard);
	ft_insertleft(minitree, command_1);
	ft_insertright(minitree, command_2);
	return (minitree);
}
