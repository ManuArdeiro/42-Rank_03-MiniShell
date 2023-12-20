/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_commandlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:30:06 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/20 20:51:13 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_commandlist(t_command **command)
{
	if (*command == NULL)
		return ;
	free((*command)->name);
	ft_lstclear(&(*command)->args, ft_free_string);
	ft_lstclear(&(*command)->infile, ft_freefile);
	ft_lstclear(&(*command)->outfile, ft_freefile);
	free(*command);
	*command = NULL;
}
