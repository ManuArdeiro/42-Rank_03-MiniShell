/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mininode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:34:11 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/14 14:36:40 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_mininode(void *content)
{
	t_mininode	*mininode;

	if (content == NULL)
		return ;
	mininode = (void *)content;
	if (mininode->content != NULL)
		free(mininode->content);
	free(mininode);
}
