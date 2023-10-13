/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:05:21 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/13 15:52:57 by yzaytoun         ###   ########.fr       */
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
	command->args = ft_lstconvert_strarr(arglist);
	command->infile = ft_lstconvert_filearr(infile);
	command->outfile = ft_lstconvert_filearr(outfile);
	free(name);
	ft_lstclear(&arglist, free);
	ft_lstclear(&infile, free);
	ft_lstclear(&outfile, free);
	return (command);
}

t_command	*ft_get_minicommand(char *commandline, t_part *tokenlist)
{
	t_part		*commandnode;
	t_command	*command;
	t_list		*arglist;
	char		*commandname;

	command = NULL;
	if (tokenlist == NULL)
		return (NULL);
	commandnode = ft_get_tokennode(tokenlist, tk_cmd, CURRENT_NODE);
	arglist = ft_extract_stringlist(commandline, tokenlist, tk_arg);
	commandname = ft_extract_tokenstring(commandline, commandnode);
	ft_lstinsert(&arglist, commandname, FRONT);
	command = ft_createcommand(
			commandname,
			arglist,
			ft_extract_filelist(commandline, tokenlist, INFILE),
			ft_extract_filelist(commandline, tokenlist, OUTFILE)
			);
	return (command);
}