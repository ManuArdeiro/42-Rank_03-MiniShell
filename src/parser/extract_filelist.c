/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_filelist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:36:15 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/15 16:57:54 by yzaytoun         ###   ########.fr       */
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

static void	ft_get_filelist(
	t_list **filelist,
	const char *commandline, t_part *tokenlist, t_bool std_stream)
{
	t_part	*node;
	t_part	*separatortoken;
	char	*string;
	t_file	*file;

	node = tokenlist;
	separatortoken = NULL;
	while (node != NULL && ft_isseparator(node->token) == FALSE)
	{
		if (ft_check_filetype(node->token, std_stream) == TRUE)
		{
			separatortoken
				= ft_get_tokennode(tokenlist, node->token, CURRENT_NODE);
			string = ft_extract_tokenstring(commandline, separatortoken->next);
			file = ft_create_file(string, std_stream, ft_get_filemode(node->token));
			ft_lstinsert(filelist, (t_file *)file, BACK);
		}
		node = node->next;
	}
}

t_list	*ft_extract_filelist(
	const char *commandline, t_part *tokenlist, t_bool std_stream)
{
	t_list	*filelist;

	filelist = NULL;
	if (commandline == NULL || tokenlist == NULL)
		return (NULL);
	ft_get_filelist(&filelist, commandline, tokenlist, std_stream);
	return (filelist);
}
