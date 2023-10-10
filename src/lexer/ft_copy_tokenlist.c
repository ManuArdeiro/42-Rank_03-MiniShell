/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_tokenlist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:23:30 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/10 11:17:45 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_part	*ft_copytoken(t_part *tokennode)
{
	t_part	*tokencopy;

	if (tokennode == NULL)
		return (NULL);
	tokencopy = malloc(sizeof(t_part));
	if (!tokencopy)
		return (NULL);
	tokencopy->end = tokennode->end;
	tokencopy->start = tokennode->start;
	tokencopy->token = tokennode->token;
	tokencopy->index = tokennode->index;
	tokencopy->used = tokennode->used;
	tokencopy->next = NULL;
	return (tokencopy);
}
