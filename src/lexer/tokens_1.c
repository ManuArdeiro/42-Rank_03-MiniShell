/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:12:50 by jolopez-          #+#    #+#             */
/*   Updated: 2023/09/21 20:26:31 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_space(char *line, int *i)
{
	return (line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\v');
}

int	ft_is_lprnths(char *line, int *i)
{
	if (line[*i] == '(')
	{
		*i++;
		return (TRUE);
	}
	return (FALSE);
}

int	ft_is_rprnths(char *line, int *i)
{
	if (line[*i] == ')')
	{
		*i++;
		return (TRUE);
	}
	return (FALSE);
}

int	ft_is_sglquot(char *line, int *i)
{
	if (line[*i] == '\'')
	{
		*i++;
		return (TRUE);
	}
	return (FALSE);
}

int	ft_is_dblquot(char *line, int *i)
{
	if (line[*i] == '\"')
	{
		*i++;
		return (TRUE);
	}
	return (FALSE);
}
