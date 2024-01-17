/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:10:05 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/17 19:10:45 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_handle_shelvl(t_global **global)
{
	char	*shelvl;

	shelvl = ft_getenv("SHLVL", (*global)->envlist);
	(*global)->shell_level = ft_atoi(shelvl);
	if (shelvl != NULL)
	{
		free(shelvl);
		shelvl = ft_itoa((*global)->shell_level + 1);
		ft_setenv(&(*global)->envlist, "SHLVL", shelvl, OVERWRITE_VALUE);
		free(shelvl);
	}
}

/*	This function first frees the list of environment strings then frees the
	global structure allocated memory.	*/

void	ft_freeglobal(t_global **global)
{
	ft_lstclear(&((*global)->envlist), ft_cleardict);
	free(*global);
}

/*	This function inits the glogal structure variable allocating memory 
	with calloc. Then it creates the environment items list depending on
	the environment passed as argument (or not) calling to ft_initenv()
	function.	*/

void	ft_initglobal(t_global **global, char **env, t_bool devmode)
{
	*global = ft_calloc(sizeof(t_global), 1);
	if (*global == NULL)
		return ;
	(*global)->devmode = devmode;
	(*global)->envlist = ft_initenv(env);
	ft_handle_shelvl(global);
}
