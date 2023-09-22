/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:51:52 by jolopez-          #+#    #+#             */
/*   Updated: 2023/09/21 21:32:08 by jolopez-         ###   ########.fr       */
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

typedef struct s_part
{
	int		index;
	int		value;
	t_part	*next;
}	t_part;

static int	ft_token(int *tokens, char *line, int *i)
{
	
}

t_part	*ft_tokenizer(char *line)
{
	int	*tokens;
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		if (ft_is_space(line, i))
			i++;
		else if (!!ft_strchr("()\'\"*;<>|&", line[i]))
			ft_token(tokens, line, &i);
		else if ()
			


			
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
