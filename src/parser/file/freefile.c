/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:37:02 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/27 20:33:51 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_freefile(void *content)
{
	t_file	*file;

	if (content == NULL)
		return ;
	file = (t_file *)content;
	if (file != NULL && file->name != NULL)
		free(file->name);
	free(file);
}
