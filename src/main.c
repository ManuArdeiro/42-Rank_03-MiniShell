/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:55:53 by jolopez-          #+#    #+#             */
/*   Updated: 2023/09/05 20:18:52 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


static int	ft_loop(t_global *global)
{
	char	*line;

	while (!global->status)
	{
		printf("%s", prompt);
		global->line = readline(prompt);
		if (ft_strncmp(line, "exit", 5) == 0)
			global->status = 1;
		free(global->line);
	}
	return (EXIT_SUCCESS);
}

static void	ft_free(t_global **global)
{
	free(global);
}

static void	ft_init(t_global **global)
{
	global = malloc(sizeof(t_global));
	ft_bzero(global, sizeof(global));
}

int	main(int ac, char **av, char **env)
{
	t_global	*global;

	if (ac >= 2)
		ft_printhelp();
	ft_printwellcome();
	ft_init(&global);
	if (ft_loop(global) != 0)
		perror("Error using minishell");
	ft_free(&global);
	return (EXIT_SUCCESS);
}
