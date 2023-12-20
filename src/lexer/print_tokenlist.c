/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokenlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:29:28 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/20 20:29:30 by yzaytoun         ###   ########.fr       */
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
		printf("%d    |  ", count);
		ft_print_token(print->token);
		printf("\n");
		print = print->next;
		count++;
	}
	printf("------------------------\n");
}
