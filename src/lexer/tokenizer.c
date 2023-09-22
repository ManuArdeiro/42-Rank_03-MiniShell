/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:51:52 by jolopez-          #+#    #+#             */
/*   Updated: 2023/09/22 20:10:33 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef enum s_token
{
	tk_lprnths = 1,
	tk_rprnths,
	tk_sglquot,
	tk_dblquot,
	tk_mul,
	tk_semi,
	tk_less,
	tk_dblless,
	tk_gtr,
	tk_dblgtr,
	tk_pipe,
	tk_or,
	tk_and,
	tk_state,
	tk_word
}	t_token;

int	ft_is_space(char *line, int *i)
{
	return (line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\v');
}

static int	ft_count_tokens(char *line)
{
	int	i;
	int	flag;
	int	tokens;
	
	i = 0;
	flag = 0;
	tokens = 0;
	while (line[i])
	{
		if (ft_is_space(line, i))
		{
			i++;
			flag = 1;
		}
		else if (!!ft_strchr("()\'\"*;<>|&", line[i]))
		{
			i++;
			tokens++;
			flag = 1;
		}
		else if (flag == 1)
		{
			tokens++;
			flag = 0;
		}
		else if (flag == 0)
			i++;
	}
	return (tokens);	
}

int	*ft_tokenizer(char *line)
{
	int	*tokens;
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	tokens = malloc(sizeof(int) * ft_count_tokens(line));
	while (line[i])
	{
		if (ft_is_space(line, i))
			i++;
		else if (!!ft_strchr("()\'\"*;<>|&", line[i]))
			ft_token(tokens, line, &i, &j);
		else if (flag == 0)
		{
			tokens[j] = tk_word;
			j++;
			i++;
		}
		else if (flag == 1)
			i++;
	}
	return (tokens);
}
