/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:11:26 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/13 20:26:17 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_tokenlist(t_part *tokenlist)
{
	t_part	*print;
	int		count;

	count = 1;
	if (tokenlist == NULL)
		return ;
	print = tokenlist;
	printf("**** Token list **** \n\n");
	printf("index | token\n");
	printf("-------------\n");
	while (print)
	{
		//printf("token %d = %d\n", print->index, print->token);
		printf("%d    |  ", count);
		ft_print_token(print->token);
		printf("\n");
		print = print->next;
		count++;
	}
	printf("------------------------\n");
}
