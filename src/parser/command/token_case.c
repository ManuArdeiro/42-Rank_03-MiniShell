/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:02:42 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/10 15:42:24 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	ft_is_tokenseries(t_part *head, t_part *next)
{
	if (head->token != tk_space && next->token != tk_space
		&& next->next != NULL && next->next->token != tk_space)
		return (TRUE);
	else if (head->token != tk_space && next->token != tk_space)
		return (TRUE);
	return (FALSE);
}

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
	if ((head->token == tk_arg
			|| head->token == tk_doll_int)
		&& ((next != NULL && next->token == tk_space) || next == NULL))
		return (CASE_2);
	else if (next != NULL
		&& ((ft_is_dollar(next->token) == TRUE
				&& ft_is_tokenpair(head->token) == FALSE)
			|| (ft_is_dollar(head->token) == TRUE)))
		return (CASE_3);
	else if ((next != NULL && head->token == tk_arg && next->token == tk_mul)
		|| (head->token == tk_mul))
		return (CASE_4);
	else if (next != NULL && (ft_is_tokenpair(head->token) == TRUE
			|| (ft_is_tokenpair(next->token) == TRUE)
			|| (ft_is_backslash_token(head->token) == TRUE)
			|| ft_is_tokenseries(head, next) == TRUE))
		return (CASE_1);
	return (FALSE);
}
