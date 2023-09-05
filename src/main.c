/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:55:53 by jolopez-          #+#    #+#             */
/*   Updated: 2023/09/05 19:34:45 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static int	ft_loop(t_global *global)
{
	char	*line;

	while (!global->status)
	{
		printf("minishell > ");
		//line = ft_read_line();
	}
	return (0);
}

static void	ft_init(t_global **global)
{
	*global = malloc(sizeof(t_global));
	ft_bzero(*global, sizeof(global));
}

int	main(int ac, char **av, char **env)
{
	t_global	*global;

	printf("\nThis is the MiniShell from yzaytoun and jolopez- for 42 project."
		"\nYou are very lucky if you are using it, enjoy it!!");
	if (ac >= 2)
		ft_printhelp();
	ft_init(&global);
	if (ft_loop(global) != 0)
		perror("Error using minishell.");
	return (0);
}
