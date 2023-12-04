/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avoid_quots.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:35:31 by jolopez-          #+#    #+#             */
/*   Updated: 2023/12/03 18:28:06 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	This function looks for an undetermined number of single quotes (it can
	even be zero) surrounded by double quotes. For example, "''''".
	If it finds such a combination, it deletes it from global-->line.	*/

static int	ft_avoid_sglquot(t_global *global)
{
	int		i;
	int		cut;
	char	*newline;

	i = 0;
	while (global->line[i])
	{
		if (global->line[i] == '\'')
		{
			cut = i;
			i++;
			while (global->line[i] == '\"')
				i++;
			if (global->line[i] == '\'')
			{
				if ((i - 1) - (cut + 2) <= 0)
					newline = ft_strjoin(ft_substr(global->line, 0, cut), 
						ft_substr(global->line, i + 1, INT32_MAX));
				else
				{
					newline = ft_strjoin(ft_substr(global->line, 0, cut), 
						ft_substr(global->line, cut + 2, (i - 1) - (cut + 2)));
					newline = ft_strjoin(newline, 
					ft_substr(global->line, i + 1, INT32_MAX));
				}
				ft_strlcpy(global->line, newline, ft_strlen(newline) + 1);
				free(newline);
				return (EXIT_FAILURE);
			}
		}
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
	char	*newline;

	i = 0;
	while (global->line[i])
	{
		if (global->line[i] == '\"')
		{
			cut = i;
			i++;
			while (global->line[i] == '\'')
				i++;
			if (global->line[i] == '\"')
			{
				if (i - cut == 1)
					newline = ft_strjoin(ft_substr(global->line, 0, cut), 
						ft_substr(global->line, i + 1, INT32_MAX));
				else
				{
					newline = ft_strjoin(ft_substr(global->line, 0, cut), 
						ft_substr(global->line, cut + 1, i - cut - 1));
					newline = ft_strjoin(newline, 
					ft_substr(global->line, i + 1, INT32_MAX));
				}
				ft_strlcpy(global->line, newline, ft_strlen(newline) + 1);
				free(newline);
				return (EXIT_FAILURE);
			}
		}
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
	return ;	
}
	
	