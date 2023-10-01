/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_filelist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:36:15 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/01 18:49:03 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_get_infillist(
	t_list **filelist, char *commandline, t_part *tokenlist)
{
	t_part	*node;
	char	*string;

	node = tokenlist;
	while (node != NULL && ft_isseparator(node->token) == FALSE)
	{
		if (node->token == tk_less || node->token == tk_dblless)
			ft_get_tokennode(tokenlist, node->token);
		string = ft_extract_tokenstring(commandline, node->next);
		ft_lstinsert(filelist, (char *)string, BACK);
		node = node->next;
	}
}

static void	ft_get_outfillist(
	t_list **filelist, char *commandline, t_part *tokenlist)
{
	t_part	*node;
	char	*string;

	node = tokenlist;
	while (node != NULL && ft_isseparator(node->token) == FALSE)
	{
		if (node->token == tk_grt || node->token == tk_dblgrt)
			ft_get_tokennode(tokenlist, node->token);
		string = ft_extract_tokenstring(commandline, node->next);
		ft_lstinsert(filelist, (char *)string, BACK);
		node = node->next;
	}
}

t_list	*ft_extract_filelist(
	char *commandline, t_part *tokenlist, t_bool filedirection)
{
	t_list	*filelist;

	filelist = NULL;
	if (commandline == NULL || tokenlist == NULL)
		return (NULL);
	if (filedirection == INFILE)
		ft_get_infilelist(&filelist, commandline, tokenlist);
	else if (filedirection == OUTFILE)
		ft_get_outfilelist(&filelist, commandline, tokenlist);
	return (filelist);
}
