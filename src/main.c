/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:55:53 by jolopez-          #+#    #+#             */
/*   Updated: 2023/09/19 21:09:11 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_loop(t_global *global)
{
	t_list	*history;

	history = NULL;
	while (global->status != EXIT)
	{
		global->line = readline(MINI_PROMPT);
		if (!global->line)
			break ;
		if (ft_strncmp(global->line, "exit", 4) == 0)
			global->status = EXIT;
		if (global->line && *global->line != 32)
		{
			ft_register_command(&history, global->line);
			add_history(global->line);
		}
		if (global->line)
		{
			free(global->line);
			global->line = NULL;
		}
	}
	rl_clear_history();
	ft_write_command_history(&history, global);
	ft_lstclear(&history, free);
	return (EXIT_SUCCESS);
}

static void	ft_free(t_global **global)
{
	ft_lstclear(&(*global)->envlist, ft_cleardict);
	free(*global);
}

static void	ft_init(t_global **global, char **env)
{
	*global = malloc(sizeof(t_global));
	if (*global == NULL)
		return ;
	ft_bzero(*global, sizeof(*global));
	(*global)->envlist = ft_initenv(env);
}

//For Debugging
/*static void	ft_panic(void)
{
	system("leaks minishell");
}*/


int	main(int ac, char **av, char **env)
{
	t_global	*global;

	//atexit(ft_panic);
	if (ac >= 2)
	{
		if (ft_strncmp(av[1], "--help", 6) == 0)
			ft_printhelp();
	}
	ft_printwellcome();
	ft_init(&global, env);
	if (ft_loop(global) != EXIT_SUCCESS)
		perror("Error using minishell");
	ft_free(&global);
	return (EXIT_SUCCESS);
}
