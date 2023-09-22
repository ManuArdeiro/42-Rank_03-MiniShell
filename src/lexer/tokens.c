/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:12:50 by jolopez-          #+#    #+#             */
/*   Updated: 2023/09/22 20:37:26 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_token(int *tokens, char *line, int *i, int *j)
{
	if (line[*i] == '(')
	{
		tokens[*j] = tk_lprnths;
		*j++;
		*i++;
	}
	else if (line[*i] == ')')
	{
		tokens[*j] = tk_rprnths;
		*j++;
		*i++;
	}
	else if (line[*i] == '\'')
	{
		tokens[*j] = tk_sglquot;
		*j++;
		*i++;
	}
	else
		ft_token_1(tokens, line, i, j);
}

static void	ft_token_1(int *tokens, char *line, int *i, int *j)
{
	if (line[*i] = '\"')
	{
		tokens[*j] == tk_dblquot;
		*j++;
		*i++;
	}
	else if (line[*i] = '*')
	{
		tokens[*j] == tk_mul;
		*j++;
		*i++;
	}
	else if (line[*i] == ';')
	{
		tokens[*j] = tk_semi;
		*j++;
		*i++;
	}
	else
		ft_token_2(tokens, line, i, j);
}

static void	ft_token_2(int *tokens, char *line, int *i, int *j)
{
	if (line[*i] == '<' && line[*i + 1] != '<')
	{
		tokens[*j] = tk_less;
		*j++;
		*i++;
	}
	else if (line[*i] == '<' && line[*i + 1] == '<')
	{
		tokens[*j] = tk_dblless;
		*j++;
		*i = *i + 2;
	}
	else if (line[*i] == '>' && line[*i + 1] != '>')
	{
		tokens[*j] = tk_gtr;
		*j++;
		*i++;
	}
	else
		ft_token_3(tokens, line, i, j);
}

static void	ft_token_3(int *tokens, char *line, int *i, int *j)
{
	if (line[*i] == '>' && line[*i + 1] == '>')
	{
		tokens[*j] = tk_dblgtr;
		*j++;
		*i = *i + 2;
	}
	else if (line[*i] == '|' && line[*i + 1] == '|')
	{
		tokens[*j] = tk_or;
		*j++;
		*i = *i + 2;
	}
	else if (line[*i] == '|' && line[*i + 1] != '|')
	{
		tokens[*j] = tk_pipe;
		*j++;
		*i++;
	}
	else
		ft_token_4(tokens, line, i, j);
}

static void	ft_token_4(int *tokens, char *line, int *i, int *j)
{
	if (line[*i] == '&' && line[*i + 1] == '!')
	{
		tokens[*j] = tk_state;
		*j++;
		*i = *i + 2;
	}
	else if (line[*i] == '&' && line[*i + 1] == '&')
	{
		tokens[*j] = tk_and;
		*j++;
		*i = *i + 2;
	}
	else if (line[*i] == '&' && line[*i + 1] != '&' && line[*i + 1] != '!')
		*i++;
}
	
	
