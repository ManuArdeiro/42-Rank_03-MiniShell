/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:53:27 by jolopez-          #+#    #+#             */
/*   Updated: 2023/09/26 20:04:48 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_token_6(t_token *tokens, char *line, int *i, int *j)
{
	if (line[*i] == '$' && line[*i + 1] != '!' )
	{
		tokens[*j] = tk_dollar;
		*j = *j + 1;
		*i = *i + 1;
	}
	else if (line[*i] == '$' && line[*i + 1] == '!' )
	{
		tokens[*j] = tk_output;
		*j = *j + 1;
		*i = *i + 2;
	}
}

void	ft_token_5(t_token *tokens, char *line, int *i, int *j)
{
	if (line[*i] == '&' && line[*i + 1] == '!')
	{
		tokens[*j] = tk_amper_exc;
		*j = *j + 1;
		*i = *i + 2;
	}
	else if (line[*i] == '&' && line[*i + 1] == '&')
	{
		tokens[*j] = tk_and;
		*j = *j + 1;
		*i = *i + 2;
	}
	else if (line[*i] == '&' && line[*i + 1] != '&' && line[*i + 1] != '!')
	{
		tokens[*j] = tk_ampersand;
		*j = *j + 1;
		*i = *i + 1;
	}
	else
		ft_token_6(tokens, line, i, j);
}
