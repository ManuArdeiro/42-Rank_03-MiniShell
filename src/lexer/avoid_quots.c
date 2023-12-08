/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avoid_quots.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:35:31 by jolopez-          #+#    #+#             */
/*   Updated: 2023/12/08 14:59:41 by yzaytoun         ###   ########.fr       */
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
	int		i;
	int		cut;

	i = 0;
	while (global->line[i] != '\0')
	{
		if (global->line[i] == '\'')
		{
			cut = i;
			i++;
			while (global->line[i] == '\"')
				i++;
			if (global->line[i] == '\'')
			{
				if (ft_get_newline1(global, i, cut) == EXIT_SUCCESS)
					return (EXIT_FAILURE);
			}
		}
		if (i < (int)ft_strlen(global->line))
			i++;
	}
	return (EXIT_SUCCESS);
}

/*	This function looks for an undetermined number of double quotes (it can
	even be zero) surrounded by simple quotes. For example, '""'.
	If it finds such a combination, it deletes it from global-->line.	*/

static int	ft_avoid_dblquot(t_global *global)
{
	int		i;
	int		cut;

	i = 0;
	while (global->line[i] != '\0')
	{
		if (global->line[i] == '\"')
		{
			cut = i;
			i++;
			while (global->line[i] == '\'')
				i++;
			if (global->line[i] == '\"')
			{
				if (ft_get_newline1(global, i, cut) == EXIT_SUCCESS)
					return (EXIT_FAILURE);
			}
		}
		if (i < (int)ft_strlen(global->line))
			i++;
	}
	return (EXIT_SUCCESS);
}

void	ft_avoid_quots(t_global *global)
{
	int	status;

	status = 1;
	//printf("oldline = %s\n", global->line);
	while (status)
	{
		status = 0;
		status = status + ft_avoid_dblquot(global);
		status = status + ft_avoid_sglquot(global);
	}
	//printf("newline = %s\n", global->line);
	return ;
}
