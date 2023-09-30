/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command_tree.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:35:44 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/30 19:49:45 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*ft_createcommand(
	char *name, t_list *arglist, t_list *infile, t_list *outfile)
{
	t_command	*command;

	command = malloc(sizeof(t_command));
	if (!command)
		return (NULL);
	command->name = ft_strdup(name);
	command->args = ft_lst_to_strarr(arglist);
	command->infile = ft_lst_to_strarr(infile);
	command->outfile = ft_lst_to_strarr(outfile);
	return (command);
}

//FIXME -> Find a separator and separate command creation
//NOTE Mark the wildcard node start

t_minitree	*ft_create_command_tree(
		char *commandline, t_part *tokenlist, t_summarizer *command_summary)
{
	t_part		*node;
	t_part		*tracer;
	t_minitree	*commandtree;
	int			command_count;

	if (tokenlist == NULL || commandline == NULL || command_summary == NULL)
		return (NULL);
	command_count = ft_get_token_count(command_summary, tk_cmd);
	while (command_count > 0)
	{
		node = ft_get_tokennode(tokenlist, tk_cmd);
		tracer = ft_get_tokennode(tokenlist, /*flag*/);
		ft_create_command(
			ft_extract_tokenstring(commandline, node),
			ft_extract_stringlist(commandline, tokenlist, tk_arg),
			ft_extract_filelist(commandline, tokenlist, INFILE),
			ft_extract_filelist(commandline, tokenlist, OUTFILE)
			);
		command_count--;
	}
	return (commandtree);
}
