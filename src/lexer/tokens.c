/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:12:50 by jolopez-          #+#    #+#             */
/*   Updated: 2023/11/23 18:49:34 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_token_5(t_part *tokens, char *line, int *i, int *ok)
{
	if (line[*i] == '$' && line[*i + 1] == '!' )
	{
		*ok = ft_add_tkn(tokens, tk_doll_exc, *i, *i + 2);
		*i = *i + 2;
	}
	else if (line[*i] == '\n')
	{
		*ok = ft_add_tkn(tokens, tk_newline, *i, *i + 1);
		*i = *i + 1;
	}
	else if (line[*i] == '=')
	{
		*ok = ft_add_tkn(tokens, tk_equal, *i, *i + 1);
		*i = *i + 1;
	}
}

static void	ft_token_4(t_part *tokens, char *line, int *i, int *ok)
{
	if (line[*i] == '|' && line[*i + 1] != '|')
	{
		*ok = ft_add_tkn(tokens, tk_pipe, *i, *i + 2);
		*i = *i + 1;
	}
	else if (line[*i] == '&' && line[*i + 1] == '&')
	{
		*ok = ft_add_tkn(tokens, tk_and, *i, *i + 2);
		*i = *i + 2;
	}
	else if (line[*i] == '&' && line[*i + 1] != '&' && line[*i + 1] != '!')
	{
		*ok = ft_add_tkn(tokens, tk_ampersand, *i, *i + 2);
		*i = *i + 2;
	}
	else if (line[*i] == '$' && line[*i + 1] != '!' )
	{
		*ok = ft_add_tkn(tokens, tk_dollar, *i, *i + 2);
		*i = *i + 1;
	}
	else
		ft_token_5(tokens, line, i, ok);
}

static void	ft_token_3(t_part *tokens, char *line, int *i, int *ok)
{
	if (line[*i] == '<' && line[*i + 1] == '<')
	{
		*ok = ft_add_tkn(tokens, tk_dblless, *i, *i + 2);
		*i = *i + 2;
	}
	else if (line[*i] == '>' && line[*i + 1] != '>')
	{
		*ok = ft_add_tkn(tokens, tk_grt, *i, *i + 1);
		*i = *i + 1;
	}
	else if (line[*i] == '>' && line[*i + 1] == '>')
	{
		*ok = ft_add_tkn(tokens, tk_dblgrt, *i, *i + 2);
		*i = *i + 2;
	}
	else if (line[*i] == '|' && line[*i + 1] == '|')
	{
		*ok = ft_add_tkn(tokens, tk_or, *i, *i + 2);
		*i = *i + 2;
	}
	else
		ft_token_4(tokens, line, i, ok);
}

static void	ft_token_2(t_part *tokens, char *line, int *i, int *ok)
{
	if (line[*i - 1])
	{
		if (line[*i] == '*' && ft_isalpha(line[*i - 1]) == FALSE)
		{
			*ok = ft_add_tkn(tokens, tk_mul, *i, *i + 1);
			*i = *i + 1;
		}
	}
	else if (!line[*i - 1] && line[*i] == '*')
	{
		*ok = ft_add_tkn(tokens, tk_mul, *i, *i + 1);
		*i = *i + 1;
	}
	else if (line[*i] == ';')
	{
		*ok = ft_add_tkn(tokens, tk_semi, *i, *i + 1);
		*i = *i + 1;
	}
	else if (line[*i] == '<' && line[*i + 1] != '<')
	{
		*ok = ft_add_tkn(tokens, tk_less, *i, *i + 1);
		*i = *i + 1;
	}
	else
		ft_token_3(tokens, line, i, ok);
}

/*	This function looks the special characters in the string line
	passed as argument and adds the corresponding token in the list of 
	tokens every time one is found.
	It uses the ft_token_2, ft_token_3 and ft_token_4 functions.	*/

int	ft_token_1(t_part *tokens, char *line, int *i)
{
	int	ok;

	if (line[*i] == '(')
	{
		ok = ft_add_tkn(tokens, tk_lprnths, *i, *i + 1);
		*i = *i + 1;
	}
	else if (line[*i] == ')')
	{
		ok = ft_add_tkn(tokens, tk_rprnths, *i, *i + 1);
		*i = *i + 1;
	}
	else if (line[*i] == '\'')
	{
		ok = ft_add_tkn(tokens, tk_sglquot, *i, *i + 1);
		*i = *i + 1;
	}
	else if (line[*i] == '\"')
	{
		ok = ft_add_tkn(tokens, tk_dblquot, *i, *i + 1);
		*i = *i + 1;
	}
	else
		ft_token_2(tokens, line, i, &ok);
	return (ok);
}
