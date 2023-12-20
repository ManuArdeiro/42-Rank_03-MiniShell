/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avoid_quots.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:35:31 by jolopez-          #+#    #+#             */
/*   Updated: 2023/12/20 20:30:39 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_newline2(t_global *global, int i, int cut)
{
	char	*part_line;
	char	*total_line;
	char	*firstpart;
	char	*secondpart;
	char	*thirdpart;

	firstpart = ft_substr(global->line, 0, cut);
	secondpart = ft_substr(global->line, cut + 1, i - cut - 1);
	thirdpart = ft_substr(global->line, i + 1, INT32_MAX);
	part_line = ft_strjoin(firstpart, secondpart);
	total_line = ft_strjoin(part_line, thirdpart);
	free(firstpart);
	free(secondpart);
	free(thirdpart);
	free(part_line);
	return (total_line);
}

static int	ft_get_newline1(t_global *global, int i, int cut)
{
	char	*newline;
	char	*firstpart;
	char	*secondpart;

	if (i - cut == 1)
	{
		firstpart = ft_substr(global->line, 0, cut);
		secondpart = ft_substr(global->line, i + 1, INT32_MAX);
		newline = ft_strjoin(firstpart, secondpart);
		free(firstpart);
		free(secondpart);
		if (!newline)
			return (EXIT_FAILURE);
	}
	else
	{
		newline = ft_get_newline2(global, i, cut);
		if (!newline)
			return (EXIT_FAILURE);
	}
	ft_strlcpy(global->line, newline, ft_strlen(newline) + 1);
	free(newline);
	return (EXIT_SUCCESS);
}

/*	This function looks for an undetermined number of single quotes (it can
	even be zero) surrounded by double quotes. For example, "''''".
	If it finds such a combination, it deletes it from global-->line.	*/

static int	ft_avoid_sglquot(t_global *global)
{
	int	i;
	int	len;
	int	simple;

	i = 0;
	simple = 0;
	len = ft_strlen(global->line);
	while (global->line[i] != '\0')
	{
		if (global->line[i] == '\"')
			simple++;
		else if (global->line[i] == '\'' && simple % 2 == 0)
		{
			if (global->line[i + 1] == '\'')
				if (ft_get_newline1(global, i + 1, i) == EXIT_SUCCESS)
					return (EXIT_FAILURE);
		}
		if (i < len)
			i++;
	}
	return (EXIT_SUCCESS);
}

/*	This function looks for an undetermined number of double quotes (it can
	even be zero) surrounded by simple quotes. For example, '""'.
	If it finds such a combination, it deletes it from global-->line.	*/

static int	ft_avoid_dblquot(t_global *global)
{
	int	i;
	int	len;
	int	simple;

	i = 0;
	simple = 0;
	len = ft_strlen(global->line);
	while (global->line[i] != '\0')
	{
		if (global->line[i] == '\'')
			simple++;
		else if (global->line[i] == '\"' && simple % 2 == 0)
		{
			if (global->line[i + 1] == '\"')
				if (ft_get_newline1(global, i + 1, i) == EXIT_SUCCESS)
					return (EXIT_FAILURE);
		}
		if (i < len)
			i++;
	}
	return (EXIT_SUCCESS);
}

void	ft_avoid_quots(t_global *global)
{
	int	status;

	status = 1;
	while (status)
	{
		status = 0;
		status = status + ft_avoid_dblquot(global);
		status = status + ft_avoid_sglquot(global);
	}
}
