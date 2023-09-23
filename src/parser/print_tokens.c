/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:23:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/23 20:29:46 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniparser.h"

void	ft_case_token(t_token token)
{
	if (token == tk_gtr)
		printf("%s\t", "tk_gtr");
	else if (token == tk_dblgtr)
		printf("%s\t", "tk_dblgtr");
	else if (token == tk_pipe)
		printf("%s\t", "tk_pipe");
	else if (token == tk_or)
		printf("%s\t", "tk_or");
	else if (token == tk_and)
		printf("%s\t", "tk_and");
	else if (token == tk_state)
		printf("%s\t", "tk_state");
	else if (token == tk_word)
		printf("%s\t", "tk_word");
}

void	ft_case_token_2(t_token token)
{
	if (token == tk_lprnths)
		printf("%s\t", "tk_lprnths");
	else if (token == tk_rprnths)
		printf("%s\t", "tk_rprnths");
	else if (token == tk_sglquot)
		printf("%s\t", "tk_sglquot");
	else if (token == tk_dblquot)
		printf("%s\t", "tk_dblquot");
	else if (token == tk_mul)
		printf("%s\t", "tk_mul");
	else if (token == tk_semi)
		printf("%s\t", "tk_semi");
	else if (token == tk_less)
		printf("%s\t", "tk_less");
	else if (token == tk_dblless)
		printf("%s\t", "tk_dblless");
}

void	ft_print_token(t_token token)
{
	if (!token)
		return ;
	ft_case_token(token);
	ft_case_token_2(token);
}
