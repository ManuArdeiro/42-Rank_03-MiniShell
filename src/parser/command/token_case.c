/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:02:42 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/31 19:15:32 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//CASE_1 = tokenpair
//CASE_2 = tk_arg , tk_mul, tk_dol_int
//CASE_3 = tk_dollar, tokenpair
//CASE_4 = tk_mul
t_bool	ft_token_case(t_part *head)
{
	t_part	*next;

	if (head == NULL)
		return (FALSE);
	next = head->next;
	if (next != NULL
		&& (ft_is_tokenpair(head->token)
			|| (ft_is_tokenpair(next->token) == TRUE)))
		return (CASE_1);
	else if ((head->token == tk_arg
			|| head->token == tk_doll_int)
		&& ((next != NULL && next->token == tk_space) || next == NULL))
		return (CASE_2);
	else if (next != NULL
		&& ((ft_is_dollar(next->token) == TRUE)
			|| (ft_is_dollar(head->token) == TRUE)))
		return (CASE_3);
	else if ((next != NULL && head->token == tk_arg && next->token == tk_mul)
		|| (head->token == tk_mul))
		return (CASE_4);
	return (FALSE);
}
