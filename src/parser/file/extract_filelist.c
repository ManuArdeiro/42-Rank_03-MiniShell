/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_filelist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:36:15 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/01 20:41:09 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	ft_check_filetype(t_token token, t_bool std_stream)
{
	if (std_stream == INFILE)
	{
		if (token == tk_less || token == tk_dblless)
			return (TRUE);
	}
	else if (std_stream == OUTFILE)
	{
		if (token == tk_grt || token == tk_dblgrt)
			return (TRUE);
	}
	return (FALSE);
}

static int	ft_get_stdstream(t_bool std_stream)
{
	if (std_stream == INFILE)
		return (STDIN_FILENO);
	else if (std_stream == OUTFILE)
		return (STDOUT_FILENO);
	return (std_stream);
}

static void	ft_get_file(
	t_list **filelist,
	t_part *separatornode, int std_stream, t_global *global
)
{
	char	*string;
	t_file	*file;

	string = NULL;
	file = NULL;
	if (separatornode == NULL)
		return ;
	string = ft_extract_tokenstring(global->line, separatornode->next);
	if (string != NULL)
	{
		string = ft_expand_dollartoken(string, global);
		file = ft_create_file(
				string,
				ft_get_stdstream(std_stream),
				ft_get_filemode(separatornode->token));
		ft_lstinsert(filelist, (t_file *)file, BACK);
		free(string);
	}
}

static t_list	*ft_get_filelist(
		t_part *tokenlist, t_bool std_stream, t_global *global)
{
	t_part	*node;
	t_list	*filelist;
	t_part	*separatornode;

	filelist = NULL;
	node = tokenlist;
	separatornode = NULL;
	while (node != NULL && ft_is_tokenseparator(node->token) == FALSE)
	{
		if (ft_is_tokenpair(node->token) == FALSE
			&& ft_is_commandseries(node) == TRUE)
			ft_skip_quotes(&node->next);
		if (ft_check_filetype(node->token, std_stream) == TRUE)
		{
			separatornode
				= ft_get_tokennode(tokenlist, node->token, TRUE, FIRST);
			ft_get_file(&filelist, separatornode, std_stream, global);
		}
		node = node->next;
	}
	return (filelist);
}

static t_list	*ft_default_filelist(int std_stream)
{
	t_list	*newfilelist;
	t_file	*file;

	newfilelist = NULL;
	file = ft_create_file(ft_strdup("STD"), std_stream, 0);
	ft_lstinsert(&newfilelist, (t_file *)file, BACK);
	return (newfilelist);
}

t_list	*ft_extract_filelist(
	t_part *tokenlist, t_bool std_stream, t_global *global)
{
	t_list	*filelist;

	filelist = NULL;
	if (global == NULL || tokenlist == NULL)
		return (NULL);
	filelist = ft_get_filelist(tokenlist, std_stream, global);
	if (filelist == NULL)
		filelist = ft_default_filelist(ft_get_stdstream(std_stream));
	return (filelist);
}
