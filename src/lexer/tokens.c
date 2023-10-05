/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:12:50 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/01 15:37:29 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_token_5(t_part *tokens, char *line, int *i)
{
	if (line[*i] == '\n')
	{
		ft_add_tkn(tokens, tk_newline, *i, *i + 1);
		*i = *i + 1;
	}
	else if (line[*i] == '=')
	{
		ft_add_tkn(tokens, tk_equal, *i, *i + 1);
		*i = *i + 1;
	}
}

static void	ft_token_4(t_part *tokens, char *line, int *i)
{
	if (line[*i] == '&' && line[*i + 1] == '&')
	{
		ft_add_tkn(tokens, tk_and, *i, *i + 2);
		*i = *i + 2;
	}
	else if (line[*i] == '&' && line[*i + 1] != '&' && line[*i + 1] != '!')
	{
		ft_add_tkn(tokens, tk_ampersand, *i, *i + 2);
		*i = *i + 2;
	}
	else if (line[*i] == '$' && line[*i + 1] != '!' )
	{
		ft_add_tkn(tokens, tk_dollar, *i, *i + 2);
		*i = *i + 1;
	}
	else if (line[*i] == '$' && line[*i + 1] == '!' )
	{
		ft_add_tkn(tokens, tk_doll_exc, *i, *i + 2);
		*i = *i + 2;
	}
	else
		ft_token_5(tokens, line, i);
}

static void	ft_token_3(t_part *tokens, char *line, int *i)
{
	if (line[*i] == '>' && line[*i + 1] != '>')
	{
		ft_add_tkn(tokens, tk_grt, *i, *i + 1);
		*i = *i + 1;
	}
	else if (line[*i] == '>' && line[*i + 1] == '>')
	{
		ft_add_tkn(tokens, tk_dblgrt, *i, *i + 2);
		*i = *i + 2;
	}
	else if (line[*i] == '|' && line[*i + 1] == '|')
	{
		ft_add_tkn(tokens, tk_or, *i, *i + 2);
		*i = *i + 2;
	}
	else if (line[*i] == '|' && line[*i + 1] != '|')
	{
		ft_add_tkn(tokens, tk_pipe, *i, *i + 2);
		*i = *i + 1;
	}
	else
		ft_token_4(tokens, line, i);
}

static void	ft_token_2(t_part *tokens, char *line, int *i)
{
	if (line[*i] == '*')
	{
		ft_add_tkn(tokens, tk_mul, *i, *i + 1);
		*i = *i + 1;
	}
	else if (line[*i] == ';')
	{
		ft_add_tkn(tokens, tk_semi, *i, *i + 1);
		*i = *i + 1;
	}
	else if (line[*i] == '<' && line[*i + 1] != '<')
	{
		ft_add_tkn(tokens, tk_less, *i, *i + 1);
		*i = *i + 1;
	}
	else if (line[*i] == '<' && line[*i + 1] == '<')
	{
		ft_add_tkn(tokens, tk_dblless, *i, *i + 2);
		*i = *i + 2;
	}
	else
		ft_token_3(tokens, line, i);
}

void	ft_token_1(t_part *tokens, char *line, int *i)
{
	if (line[*i] == '(')
	{
		ft_add_tkn(tokens, tk_lprnths, *i, *i + 1);
		*i = *i + 1;
	}
	else if (line[*i] == ')')
	{
		ft_add_tkn(tokens, tk_rprnths, *i, *i + 1);
		*i = *i + 1;
	}
	else if (line[*i] == '\'')
	{
		ft_add_tkn(tokens, tk_sglquot, *i, *i + 1);
		*i = *i + 1;
	}
	if (line[*i] == '\"')
	{
		ft_add_tkn(tokens, tk_dblquot, *i, *i + 1);
		*i = *i + 1;
	}
	else
		ft_token_2(tokens, line, i);
}
