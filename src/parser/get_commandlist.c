/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commandlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:35:44 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/04 11:08:18 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_command	*ft_createcommand(
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

static t_command	*ft_get_minicommand(char *commandline, t_part *tokenlist)
{
	t_part		*commandnode;
	t_command	*command;
	t_list		*arglist;
	char		*commandname;

	command = NULL;
	if (tokenlist == NULL)
		return (NULL);
	commandnode = ft_get_tokennode(tokenlist, tk_cmd);
	arglist = ft_extract_stringlist(commandline, tokenlist, tk_arg);
	commandname = ft_extract_tokenstring(commandline, commandnode);
	ft_lstinsert(&arglist, commandname, FRONT);
	command = ft_create_command(
			commandname,
			arglist,
			ft_extract_filelist(commandline, tokenlist, INFILE),
			ft_extract_filelist(commandline, tokenlist, OUTFILE)
			);
	return (command);
}

static t_part	*ft_get_nextcommand(t_part *tokenlist)
{
	static t_part	*tracernode;

	if (!tokenlist)
		return (NULL);
	if (!tracernode)
		tracernode = tokenlist;
	while (tracernode != NULL
		&& ft_isseparator(tracernode->token) == FALSE)
		tracernode = tracernode->next;
	return (tracernode);
}

t_list	*ft_get_commandlist(
		char *commandline, t_part *tokenlist, t_summarizer *command_summary)
{
	t_list		*commandlist;
	t_part		*tracernode;
	int			command_count;
	t_command	*minicommand;

	commandlist = NULL;
	if (tokenlist == NULL || commandline == NULL || command_summary == NULL)
		return (NULL);
	command_count = ft_get_tokencount(command_summary, tk_cmd);
	tracernode = tokenlist;
	while (command_count > 0 || tracernode != NULL)
	{
		tracernode = ft_get_nextcommand(tokenlist);
		if (ft_isseparator(tracernode->token) == TRUE)
			ft_lstinsert(
				&commandlist, (void *)(uintptr_t)tracernode->token, BACK);
		minicommand = ft_get_minicommand(commandline, tracernode->next);
		ft_printcommand(minicommand);
		ft_lstinsert(&commandlist, (t_command *)minicommand, BACK);
		command_count--;
	}
	return (commandlist);
}
