/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_filelist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:36:15 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/04 13:51:44 by yzaytoun         ###   ########.fr       */
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

static char	*ft_get_filestring(
		t_part **node, t_global *global, t_part **filenode, int file_mode)
{
	char	*string;

	string = NULL;
	if (ft_token_case(*node) == CASE_1)
	{
		if (file_mode == O_HEREDOC)
			global->fileflag = TRUE;
		string = ft_extractseries((*node), global);
		global->fileflag = FALSE;
	}
	else if (ft_token_case(*node) == CASE_2)
	{
		string = ft_extract_dollarstring(global->line, *node);
		if (file_mode != O_HEREDOC)
			string = ft_expand_dollartoken(string, global);
	}
	else
	{
		*filenode = ft_get_tokennode((*node), tk_file, TRUE, FIRST);
		string = ft_extract_tokenstring(global->line, *filenode);
		if (file_mode != O_HEREDOC)
			string = ft_expand_dollartoken(string, global);
	}
	return (string);
}

static void	ft_get_file(
	t_list **filelist,
	t_part **node, int std_stream, t_global *global
)
{
	char	*string;
	t_file	*file;
	t_part	*filenode;
	int		file_mode;

	string = NULL;
	filenode = NULL;
	file_mode = ft_get_filemode((*node)->token);
	if ((*node)->next != NULL && (*node)->next->token != tk_space)
		(*node) = (*node)->next;
	else if ((*node)->next != NULL && (*node)->next->token == tk_space)
		(*node) = (*node)->next->next;
	string = ft_get_filestring(node, global, &filenode, file_mode);
	if (string != NULL)
	{
		file = ft_create_file(string, ft_get_stdstream(std_stream), file_mode);
		ft_lstinsert(filelist, (t_file *)file, BACK);
		free(string);
		(*node) = filenode;
	}
}

t_list	*ft_extract_filelist(
		t_part *tokenlist, t_bool std_stream, t_global *global)
{
	t_list	*filelist;
	t_part	*node;

	filelist = NULL;
	if (global == NULL || tokenlist == NULL)
		return (NULL);
	node = tokenlist;
	while (node != NULL && ft_is_tokenseparator(node->token) == FALSE)
	{
		if (ft_is_tokenpair(node->token) == TRUE)
			node = ft_skip_tokens(node->next, ft_is_tokenpair);
		if (node != NULL && node->used != TRUE
			&& ft_check_filetype(node->token, std_stream) == TRUE)
			ft_get_file(&filelist, &node, std_stream, global);
		if (node != NULL)
			node = node->next;
	}
	if (filelist == NULL)
		filelist = ft_default_filelist(ft_get_stdstream(std_stream));
	return (filelist);
}
