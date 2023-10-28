/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_filelist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:37:02 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/28 19:39:42 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_filelist(void *content)
{
	t_file	*file;

	if (content == NULL)
		return ;
	file = (t_file *)content;
	if (file->name != NULL)
		free(file->name);
	free(file);
}