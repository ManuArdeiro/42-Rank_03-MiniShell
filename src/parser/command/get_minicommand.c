/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_minicommand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:05:21 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/28 15:51:02 by yzaytoun         ###   ########.fr       */
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

static t_command	*ft_newcommand(const char *commandline, t_part *tokenlist)
{
	t_command	*newcommand;
	t_part		*commandnode;
	t_list		*arglist;
	char		*commandname;

	newcommand = NULL;
	if (tokenlist == NULL || commandline == NULL)
		return (NULL);
	commandnode = ft_get_tokennode(tokenlist, tk_cmd);
	commandname = ft_extract_tokenstring(commandline, commandnode);
	arglist = ft_extract_arglist(commandline, tokenlist);
	ft_lstinsert(&arglist, commandname, FRONT);
	newcommand = ft_createcommand(
			commandname,
			arglist,
			ft_extract_filelist(commandline, tokenlist, INFILE),
			ft_extract_filelist(commandline, tokenlist, OUTFILE)
			);
	return (newcommand);
}

t_minitree	*ft_get_minicommand(const char *commandline, t_part *tokenlist)
{
	t_minitree	*minitree;
	t_command	*command;
	t_mininode	*minicommand;

	minitree = NULL;
	minicommand = NULL;
	if (tokenlist == NULL || commandline == NULL)
		return (NULL);
	command = ft_newcommand(commandline, tokenlist);
	minicommand = ft_create_mininode((t_command *)command, n_command);
	ft_treeinsert(&minitree, NULL, minicommand, NULL);
	return (minitree);
}
