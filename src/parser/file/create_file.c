/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:44:00 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/28 20:21:33 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_file	*ft_create_file(const char *name, int std_stream, int mode)
{
	t_file	*newfile;

	newfile = NULL;
	if (name == NULL)
		return (NULL);
	newfile = malloc(sizeof(t_file));
	if (!newfile)
		return (NULL);
	newfile->name = (char *)name;
	newfile->fd[0] = std_stream;
	newfile->mode = mode;
	return (newfile);
}
