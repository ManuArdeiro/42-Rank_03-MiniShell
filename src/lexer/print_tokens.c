/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:11:26 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/11 12:27:42 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_tokenlist(t_part *tokenlist)
{
	t_part	*print;

	if (tokenlist == NULL)
		return ;
	print = tokenlist;
	while (print)
	{
		printf("token %d = %d\t", print->index, print->token);
		ft_print_token(print->token);
		print = print->next;
	}
}
