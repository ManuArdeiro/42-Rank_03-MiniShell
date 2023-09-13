/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:55:53 by jolopez-          #+#    #+#             */
/*   Updated: 2023/09/13 18:50:10 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static int	ft_loop(t_global *global)
{
	t_list	*history;

	history = NULL;
	while (global->status != TRUE)
	{
		global->line = readline(MINI_PROMPT);
		if (!global->line)
			break ;
		if (ft_strncmp(global->line, "exit", 4) == 0)
			global->status = TRUE;
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
	ft_write_command_history(&history);
	ft_lstclear(&history, free);
	return (EXIT_SUCCESS);
}

static void	ft_free(t_global **global)
{
	free(*global);
}

static void	ft_init(t_global **global)
{
	*global = malloc(sizeof(t_global));
	if (*global)
		return ;
	ft_bzero(*global, sizeof(*global));
}

int	main(int ac, char **av)
{
	t_global	*global;

	(void)av;
	if (ac >= 2)
		ft_printhelp();
	ft_printwellcome();
	ft_init(&global);
	if (ft_loop(global) != 0)
		perror("Error using minishell");
	ft_free(&global);
	return (EXIT_SUCCESS);
}
