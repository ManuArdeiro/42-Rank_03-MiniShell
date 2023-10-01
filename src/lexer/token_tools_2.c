/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tools_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:30:15 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/01 15:35:54 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_check_sgltoken(char *line, int *i, int *flag, int *tokens)
{
	if (ft_strchr("()\'\"*;<>|&", line[*i]))
	{
		*i = *i + 1;
		*tokens = *tokens + 1;
		*flag = 1;
	}
	else if (*flag == 1)
	{
		*tokens = *tokens + 1;
		*flag = 0;
	}
	else if (*flag == 0)
		*i = *i + 1;
}

static void	ft_check_dbltoken(char *line, int *i, int *flag, int *tokens)
{
	char	*str;

	str = ft_substr(line, *i, 2);
	if (ft_strncmp("<<", str, 2) == 0 || ft_strncmp(">>", str, 2) == 0)
	{
		*i = *i + 2;
		*tokens = *tokens + 1;
		*flag = *flag + 1;
	}
	else if (ft_strncmp("||", str, 2) == 0)
	{
		*i = *i + 2;
		*tokens = *tokens + 1;
		*flag = *flag + 1;
	}
	else if (ft_strncmp("&!", str, 2) == 0 || ft_strncmp("&&", str, 2) == 0)
	{
		*i = *i + 2;
		*tokens = *tokens + 1;
		*flag = *flag + 1;
	}
	else
		ft_check_sgltoken(line, i, flag, tokens);
	free(str);
}

int	ft_count_tokens(char *line)
{
	int		i;
	int		flag;
	int		tokens;

	i = 0;
	flag = 1;
	tokens = 0;
	while (line[i])
	{
		if (ft_is_space(line, i))
		{
			i++;
			flag = 1;
		}
		else
			ft_check_dbltoken(line, &i, &flag, &tokens);
	}
	return (tokens);
}

static void	ft_get_tokens_2(char *line, t_part *tokens, int *i, int *start)
{	
	if (*start == -1 && (ft_strchr("()\'\"*;<>|&", line[*i + 1])
		|| ft_is_space(line, *i + 1)))
	{
		ft_add_tkn(tokens, tk_cmd, *i, *i + 1);
		*i = *i + 1;
	}
	else if (*start == -1)
	{
		*start = *i;
		*i = *i + 1;
	}
	else if (*start != -1 && (ft_strchr("()\'\"*;<>|&", line[*i + 1])
			|| ft_is_space(line, *i + 1)))
	{
		ft_add_tkn(tokens, tk_cmd, *start, *i);
		*i = *i + 1;
	}
	else if (*start != -1 && !ft_strchr("()\'\"*;<>|&", line[*i + 1])
		&& !ft_is_space(line, *i + 1))
	{
		*i = *i + 1;
	}
}

void	ft_get_tokens(char *line, t_part *tokens)
{
	int	i;
	int	start;

	start = -1;
	i = 0;
	while (line[i])
	{
		if (ft_is_space(line, i))
		{
			i = i + 1;
			start = -1;
		}
		else if (ft_strchr("()\'\"*;<>|&", line[i]))
		{
			ft_token_1(tokens, line, &i);
			start = -1;
		}
		else
			ft_get_tokens_2(line, tokens, &i, &start);
	}
}
