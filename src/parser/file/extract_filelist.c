/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_filelist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:36:15 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/10 19:56:46 by jolopez-         ###   ########.fr       */
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
	t_part **node, int std_stream, t_global *global
)
{
	t_part	*filenode;
	char	*string;
	t_file	*file;

	string = NULL;
	file = NULL;
	filenode = ft_get_tokennode((*node)->next, tk_file, TRUE, FIRST);
	string = ft_extract_tokenstring(global->line, filenode);
	if (string != NULL)
	{
		string = ft_expand_dollartoken(string, global);
		file = ft_create_file(
				string,
				ft_get_stdstream(std_stream),
				ft_get_filemode((*node)->token));
		ft_lstinsert(filelist, (t_file *)file, BACK);
		free(string);
		(*node) = filenode;
	}
}

static void	ft_get_filelist(
		t_list **filelist,
		t_part *tokenlist, t_bool std_stream, t_global *global)
{
	t_part	*node;

	node = tokenlist;
	while (node != NULL && ft_is_tokenseparator(node->token) == FALSE)
	{
		if (ft_is_tokenpair(node->token) == TRUE
			&& (ft_is_commandseries(tokenlist) == TRUE
				|| ft_tokenlist_contains(node, ft_is_redirection) == TRUE))
			node = ft_skip_tokens(node->next, ft_is_tokenpair);
		if (node != NULL)
		{
			if (ft_check_filetype(node->token, std_stream) == TRUE)
				ft_get_file(filelist, &node, std_stream, global);
			node = node->next;
		}
	}
}

t_list	*ft_extract_filelist(
		t_part *tokenlist, t_bool std_stream, t_global *global)
{
	t_list	*filelist;

	filelist = NULL;
	if (global == NULL || tokenlist == NULL)
		return (NULL);
	ft_get_filelist(&filelist, tokenlist, std_stream, global);
	if (filelist == NULL)
		filelist = ft_default_filelist(ft_get_stdstream(std_stream));
	return (filelist);

}