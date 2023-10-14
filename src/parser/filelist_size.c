/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filelist_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:58:09 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/14 19:01:25 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_filelist_size(t_file *filelist)
{
	int	len;

	len = 0;
	if (filelist == NULL)
		return (len);
	while (filelist[len].name != NULL)
		++len;
	return (len);
}
