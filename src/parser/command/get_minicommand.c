/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_minicommand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:05:21 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/05 20:57:42 by yzaytoun         ###   ########.fr       */
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
	command->args = arglist;
	command->infile = infile;
	command->outfile = outfile;
	return (command);
}

static t_command	*ft_create_newcommand(
	char *commandname, t_part *tokenlist, t_global *global
)
{
	t_command	*newcommand;
	t_list		*arglist;

	newcommand = NULL;
	arglist = NULL;
	arglist = ft_extract_arglist(tokenlist, global);
	arglist = ft_clear_emptyvalues(arglist);
	if ((commandname == NULL || ft_strlen(commandname) == 0)
		&& (arglist != NULL && arglist->content != NULL))
		commandname = ft_strdup((char *)arglist->content);
	else if (commandname != NULL)
		ft_lstinsert(&arglist, commandname, FRONT);
	newcommand
		= ft_createcommand(
			commandname,
			arglist,
			ft_extract_filelist(tokenlist, INFILE, global),
			ft_extract_filelist(tokenlist, OUTFILE, global)
			);
	if (newcommand != NULL)
		ft_expand_filelist(&newcommand->infile, global);
	return (newcommand);
}

static t_command	*ft_newcommand(t_part *tokenlist, t_global *global)
{
	t_command	*newcommand;
	t_part		*commandnode;
	char		*commandname;

	newcommand = NULL;
	if (ft_is_commandseries(tokenlist) == FALSE)
	{
		commandnode = ft_get_tokennode(tokenlist, tk_cmd, TRUE, FIRST);
		commandname = ft_extract_tokenstring(global->line, commandnode);
		ft_checkquotes(&commandname);
		global->expand_dollartoken = TRUE;
	}
	else
		commandname
			= ft_extract_commandseries(
				global->line, tokenlist, NULL, global);
	if (global->expand_dollartoken == TRUE)
		commandname = ft_expand_dollartoken(commandname, global);
	newcommand
		= ft_create_newcommand(commandname, tokenlist, global);
	global->expand_dollartoken = FALSE;
	return (newcommand);
}

t_minitree	*ft_get_minicommand(t_part *tokenlist, t_global *global)
{
	t_minitree	*minitree;
	t_command	*command;
	t_mininode	*minicommand;

	minitree = NULL;
	minicommand = NULL;
	if (tokenlist == NULL || global == NULL)
		return (NULL);
	command = ft_newcommand(tokenlist, global);
	minicommand = ft_create_mininode((t_command *)command, n_command);
	ft_treeinsert(&minitree, NULL, minicommand, NULL);
	return (minitree);
}
