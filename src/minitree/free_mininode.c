/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mininode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:34:11 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/16 13:18:50 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_mininode(void *content)
{
	t_mininode	*mininode;
	t_part		*tokenlist;
	t_command	*command;

	if (content == NULL)
		return ;
	mininode = (t_mininode *)content;
	if (mininode->content != NULL)
	{
		if (ft_is_compoundcommand(mininode->type) == TRUE
			|| mininode->type == n_pipeline
			|| mininode->type == n_empty)
		{
			tokenlist = (t_part *)mininode->content;
			ft_free_tokenlist(&tokenlist);
		}
		else if (mininode->type == n_command
			|| mininode->type == n_subshellcommand)
		{
			command = (t_command *)mininode->content;
			ft_free_commandlist(&command);
		}
		mininode->content = NULL;
	}
	free(mininode);
}
