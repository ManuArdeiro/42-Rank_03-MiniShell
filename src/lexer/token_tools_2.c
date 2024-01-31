/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tools_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:30:15 by jolopez-          #+#    #+#             */
/*   Updated: 2024/01/31 18:58:13 by jolopez-         ###   ########.fr       */
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
	else if (*flag != 0)
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

/*	This function returs the number of tokens in a string passed as 
	argument, looking for the special characters which are tokens or 
	separate the tokens.
	It continues in ft_check_dbltoken and ft_check_sgltoken	functions.	*/

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

/*	This function is the continuation of ft_get_tokens function.	*/

static void	ft_get_tokens_2(char *line, t_part *tokens, int *i, int *start)
{
	if ((*start < 0 && ft_strchr("()\'\"*;<>|&", (int)line[*i + 1]))
		|| (*start < 0 && ft_is_space(line, *i + 1)))
		ft_evaluatetoken(tokens, line, i, (int *)0);
	else if (*start < 0)
	{
		*start = *i;
		*i = *i + 1;
		if (line[*i] == '\0')
			ft_add_tkn(tokens, tk_cmd, *start, *i);
	}
	else if (*start >= 0 && (ft_strchr("()\'\";*<>|&", line[*i + 1])
			|| ft_is_space(line, *i + 1) || line[*i +1] == '\n'))
	{
		ft_add_tkn(tokens, tk_cmd, *start, *i);
		*start = -1;
		*i = *i + 1;
	}
	else if (*start >= 0 && !ft_strchr("()\'\"*;<>|&", line[*i + 1])
		&& !ft_is_space(line, *i + 1))
		*i = *i + 1;
}

/*	This function looks for the different tokens in the string passed as 
	argument. 
	-	When a special character is found the ft_token_1 function is used
		to recognize it.
	-	When a "word" is found it uses the ft_add_tkn to add it as a 
		command.	
	-	This function continues in ft_get_tokens_2 function.	*/

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
			if (ft_last_tkn(tokens)->token != tk_space)
				ft_add_tkn(tokens, tk_space, i - 1, i - 1);
		}
		else if (ft_strchr("()\"\'*;<>|&$", line[i]))
		{
			ft_token_1(tokens, line, &i);
			start = -1;
		}
		else
			ft_get_tokens_2(line, tokens, &i, &start);
	}
}
