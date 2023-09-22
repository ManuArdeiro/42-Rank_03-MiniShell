/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:26:54 by jolopez-          #+#    #+#             */
/*   Updated: 2023/09/21 21:22:48 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_mul(char *line, int *i)
{
	if (line[*i] == '*')
	{
		*i++;
		return (TRUE);
	}
	return (FALSE);
}

int	ft_is_semi(char *line, int *i)
{
	if (line[*i] == ';')
	{
		*i++;
		return (TRUE);
	}
	return (FALSE);
}




int	is_redirection(char c)
{
	return (!!ft_strchr("><", c));
}

int	is_reserved_char(char c)
{
	return (is_redirection(c) || is_connector(c) || is_parenthesis(c));
}

int	is_word(char c)
{
	return (!is_reserved_char(c));
}

static int	ft_token(char *line, int *i)
{
	int	value;

	if (c == '|' && d != '|')
		value = tk_pipe;
	else if (c == '|' && d == '|')
		value = tk_or;
	else if (c == '&' && d != '&')
		value = tk_ampersand;
	else if (c == '&' && d == '&')
		value = tk_and;
	else if (c == '<' && d != '<')
		value = tk_less;
	else if (c == '<' && d == '<')
		value = tk_dblless;
	else if (c == '>' && d != '>')
		value = tk_gtr;
	else if (c == '>' && d == '>')
		value = tk_dblgtr;
	else if (c == '\'')
		value = tk_sglquot;
	else if (c == '\"')
		value = tk_dblquot;
	else if (c == '*')
		value = tk_mul;
	return (value);
}