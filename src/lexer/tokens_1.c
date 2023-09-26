/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:12:50 by jolopez-          #+#    #+#             */
/*   Updated: 2023/09/26 20:02:49 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_token_4(t_token *tokens, char *line, int *i, int *j)
{
	if (line[*i] == '>' && line[*i + 1] == '>')
	{
		tokens[*j] = tk_dblgtr;
		*j = *j + 1;
		*i = *i + 2;
	}
	else if (line[*i] == '|' && line[*i + 1] == '|')
	{
		tokens[*j] = tk_or;
		*j = *j + 1;
		*i = *i + 2;
	}
	else if (line[*i] == '|' && line[*i + 1] != '|')
	{
		tokens[*j] = tk_pipe;
		*j = *j + 1;
		*i = *i + 1;
	}
	else
		ft_token_5(tokens, line, i, j);
}

void	ft_token_3(t_token *tokens, char *line, int *i, int *j)
{
	if (line[*i] == '<' && line[*i + 1] != '<')
	{
		tokens[*j] = tk_less;
		*j = *j + 1;
		*i = *i + 1;
	}
	else if (line[*i] == '<' && line[*i + 1] == '<')
	{
		tokens[*j] = tk_dblless;
		*j = *j + 1;
		*i = *i + 2;
	}
	else if (line[*i] == '>' && line[*i + 1] != '>')
	{
		tokens[*j] = tk_gtr;
		*j = *j + 1;
		*i = *i + 1;
	}
	else
		ft_token_4(tokens, line, i, j);
}

void	ft_token_2(t_token *tokens, char *line, int *i, int *j)
{
	if (line[*i] == '\"')
	{
		tokens[*j] = tk_dblquot;
		*j = *j + 1;
		*i = *i + 1;
	}
	else if (line[*i] == '*')
	{
		tokens[*j] = tk_mul;
		*j = *j + 1;
		*i = *i + 1;
	}
	else if (line[*i] == ';')
	{
		tokens[*j] = tk_semi;
		*j = *j + 1;
		*i = *i + 1;
	}
	else
		ft_token_3(tokens, line, i, j);
}

void	ft_token_1(t_token *tokens, char *line, int *i, int *j)
{
	if (line[*i] == '(')
	{
		tokens[*j] = tk_lprnths;
		*j = *j + 1;
		*i = *i + 1;
	}
	else if (line[*i] == ')')
	{
		tokens[*j] = tk_rprnths;
		*j = *j + 1;
		*i = *i + 1;
	}
	else if (line[*i] == '\'')
	{
		tokens[*j] = tk_sglquot;
		*j = *j + 1;
		*i = *i + 1;
	}
	else
		ft_token_2(tokens, line, i, j);
}
