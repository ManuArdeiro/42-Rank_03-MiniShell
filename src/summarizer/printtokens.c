/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:23:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/27 17:47:53 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniparser.h"

void	ft_case_token(t_token token)
{
	if (token == tk_grt)
		printf("%s\t", "tk_grt");
	else if (token == tk_dblgrt)
		printf("%s\t", "tk_dblgrt");
	else if (token == tk_pipe)
		printf("%s\t", "tk_pipe");
	else if (token == tk_or)
		printf("%s\t", "tk_or");
	else if (token == tk_and)
		printf("%s\t", "tk_and");
	else if (token == tk_doll_int)
		printf("%s\t", "tk_doll_int");
	else if (token == tk_dollar)
		printf("%s\t", "tk_dollar");
	else if (token == tk_ampersand)
		printf("%s\t", "tk_ampersand");
	else if (token == tk_space)
		printf("%s\t", "tk_space");
}

void	ft_case_token_2(t_token token)
{
	if (token == tk_lprnths)
		printf("%s\t", "tk_lprnths");
	else if (token == tk_rprnths)
		printf("%s\t", "tk_rprnths");
	else if (token == tk_sglquot)
		printf("%s\t", "tk_sglquot");
	else if (token == tk_cmd)
		printf("%s\t", "tk_cmd");
	else if (token == tk_arg)
		printf("%s\t", "tk_arg");
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
	else if (token == tk_file)
		printf("%s\t", "tk_file");
}

void	ft_print_token(t_token token)
{
	if (!token)
		return ;
	ft_case_token(token);
	ft_case_token_2(token);
}
