/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:23:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/22 20:34:27 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniparser.h"

void	ft_printtokens(t_token token)
{
	if (token == tk_gtr)
		printf("%s", "tk_lprnths");
	if (token == tk_dblgtr)
		printf("%s", "tk_lprnths");
	if (token == tk_pipe)
		printf("%s", "tk_lprnths");
	if (token == tk_or)
		printf("%s", "tk_lprnths");
	if (token == tk_and)
		printf("%s", "tk_lprnths");
	if (token == tk_state)
		printf("%s", "tk_lprnths");
	if (token == tk_word)
		printf("%s", "tk_lprnths");
}

void	ft_printtokens(t_token token)
{
	if (token == tk_lprnths)
		printf("%s", "tk_lprnths");
	if (token == tk_rprnths)
		printf("%s", "tk_lprnths");
	if (token == tk_sglquot)
		printf("%s", "tk_lprnths");
	if (token == tk_dblquot)
		printf("%s", "tk_lprnths");
	if (token == tk_mul)
		printf("%s", "tk_lprnths");
	if (token == tk_semi)
		printf("%s", "tk_lprnths");
	if (token == tk_less)
		printf("%s", "tk_lprnths");
	if (token == tk_dblless)
		printf("%s", "tk_lprnths");
	else
		ft_printtokens_2(token);
}