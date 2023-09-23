/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:51:52 by jolopez-          #+#    #+#             */
/*   Updated: 2023/09/23 19:23:06 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_get_tokens(char *line, t_token *tokens, int *i, int *j)
{
	int	flag;

	flag = 1;
	while (line[*i])
	{
		if (ft_is_space(line, i))
		{
			*i = *i + 1;
			flag = 1;
		}
		else if (ft_strchr("()\'\"*;<>|&", line[*i]))
		{
			ft_token(tokens, line, i, j);
			flag = 1;
		}
		else if (flag == 1)
		{
			tokens[*j] = tk_word;
			*j = *j + 1;
			*i = *i + 1;
			flag = 0;
		}
		else if (flag == 0)
			*i = *i + 1;
	}
}

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

static int	ft_count_tokens(char *line)
{
	int		i;
	int		flag;
	int		tokens;

	i = 0;
	flag = 1;
	tokens = 0;
	while (line[i])
	{
		if (ft_is_space(line, &i))
		{
			i++;
			flag = 1;
		}
		else
			ft_check_dbltoken(line, &i, &flag, &tokens);
	}
	return (tokens);
}

t_token	*ft_tokenizer(char *line, int *tk_number)
{
	int		i;
	int		j;
	t_token	*tokens;

	i = 0;
	j = 0;
	*tk_number = ft_count_tokens(line);
	tokens = malloc(sizeof(int) * *tk_number);
	if (!tokens)
		exit(1);
	ft_get_tokens(line, tokens, &i, &j);
	return (tokens);
}
