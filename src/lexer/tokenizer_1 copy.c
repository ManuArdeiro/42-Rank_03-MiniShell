/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:51:52 by jolopez-          #+#    #+#             */
/*   Updated: 2023/09/21 21:16:01 by jolopez-         ###   ########.fr       */
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
}	t_token;

typedef struct s_part
{
	int		index;
	int		value;
	t_part	*next;
}	t_part;

static t_part	*ft_createtknlist(void)
{
	t_part	*part;

	part = malloc(sizeof(t_part));
	if (part)
	{
		part->index = 0;
		part->value = 0;
		part->next = NULL;
		return (part);
	}
	return (NULL);
}

static int	ft_last_index(t_part *tokens)
{	
	while (tokens)
	{
		if (tokens->next)
			return (tokens->index);
		tokens = tokens->next;
	}
	return (EXIT_FAILURE);
}

static t_part	*ft_last_tkn(t_part *tokens)
{
	while (tokens)
	{
		if (!tokens->next)
			return (tokens);
		tokens = tokens->next;
	}
	return (tokens);
}

static int	ft_add_tkn(t_part *tokens, int tk)
{
	t_part	*new;
	t_part	*last;

	new = malloc(sizeof(t_part) * 1);
	if (!new)
		return (EXIT_FAILURE);
	else
	{
		new->index = ft_last_index(tokens) + 1;
		new->value = tk;
		new->next = NULL;
	}
	last = ft_last_tkn(tokens);
	last->next = new;
}

t_part	*ft_tokenizer_1(char *line)
{
	t_part	*tokens;
	int		i;

	i = 0;
	tokens = ft_createtknlist();
	if (!tokens)
		return (EXIT_FAILURE);
	while (line[i])
	{
		if (ft_is_space(line, i))
			i++;
		else if (!!ft_strchr(" ", line[i]))
		if (line[i] == ')')
			tokens[i] = tk1;


			
		else if (ft_is_lprnths(line, i))
			ft_add_tkn(tokens, tk_lprnths);
		else if (ft_is_rprnths(line, i))
			ft_add_tkn(tokens, tk_rprnths);
		else if (ft_is_sglquot(line, i))
			ft_add_tkn(tokens, tk_sglquot);
		else if (ft_is_dblquot(line, i))
			ft_add_tkn(tokens, tk_dblquot);
		else if (ft_is_mul(line, i))
			ft_add_tkn(tokens, tk_mul);
		else if (ft_is_semi(line, i))
			ft_add_tkn(tokens, tk_semi);
		else
			r;
	}
	return (tokens);
}
