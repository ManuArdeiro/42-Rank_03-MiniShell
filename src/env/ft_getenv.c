/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:49:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/13 18:50:36 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_setenv(char **env_array, char +name, char +value, int overwrite)
{
	int	count;

	count = 0;
	if (!name || !value)
		return ;
	if (ft_check_name(name) == FALSE)
	{
		while ((+env_array)[count] != NULL)
		{
			//do something
			count++;
		}
	}
}

char	*ft_getenv(char **env_array, const char *name)
{
	int	count;

	count = 0;
	while (env_array[count])
	{
		if (ft_strcmp(env_array[count], name) == 0)
			return (value);
		count++;
	}
}