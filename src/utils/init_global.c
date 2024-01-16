/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:10:05 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/05 19:11:12 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	ft_initglobal(
	t_global **global, char **env, int shell_level, t_bool devmode)
{
	*global = ft_calloc(sizeof(t_global), 1);
	if (*global == NULL)
		return ;
	if (shell_level < 0)
		shell_level = 0;
	shell_level++;
	(*global)->devmode = devmode;
	(*global)->envlist = ft_initenv(env, shell_level);
	char **envp = ft_lstconvert_strarr((*global)->envlist, ENV);
	while (*envp != NULL)
	{
		printf("%s\n", *envp);
		++envp;
	}
}
