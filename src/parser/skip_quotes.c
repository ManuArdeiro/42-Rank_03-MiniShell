/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:26:41 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/30 20:30:25 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_skip_quotes(t_part **token)
{
	if (*token == NULL)
		return ;
	while (*token != NULL && ft_is_tokenpair((*token)->token) == FALSE)
		*token = (*token)->next;
}
