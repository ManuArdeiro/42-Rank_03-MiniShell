/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:55:53 by jolopez-          #+#    #+#             */
/*   Updated: 2024/01/22 20:44:12 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_register_and_clean(
		t_list **history, t_global **global, t_minitree **parsetree)
{
	if ((*global)->line && *((*global)->line))
	{
		ft_register_command(history, (*global)->line);
		add_history((*global)->line);
		free((*global)->line);
		(*global)->line = NULL;
	}
	ft_destroytree(parsetree, ft_free_mininode);
}

/*	The loop will be running continuously as long as "exit" is not written on 
	the command line: 
	-	It will read every phrase typed on the command line (using readline()
		function and will pass it to the tokenizer to recognize the diffetent
		tokens.
	-	Then will call the parser.
	*/

void	ft_resetvariables(t_global *global)
{
	global->signallist.sa_handler = &ft_signal_handler;
	sigaction(SIGINT, &global->signallist, NULL);
	global->signallist.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &global->signallist, NULL);
}

static void	ft_loop(t_global *global)
{
	t_list		*history;
	t_minitree	*parsetree;

	history = NULL;
	ft_initsignals(global);
	while (global->status != EXITED)
	{
		ft_resetvariables(global);
		global->line = readline(MINI_PROMPT);
		if (global->line != NULL)
		{
			global->line = ft_get_completeline(global->line, global);
			if (ft_strequal("exit", global->line) == TRUE)
				global->status = EXITED;
			parsetree = ft_parse_commandline(global);
			ft_execute_commandline(parsetree, global);
			ft_register_and_clean(&history, &global, &parsetree);
		}
		else
			global->status = EXITED;
	}
	ft_write_command_history(&history, global);
	ft_lstclear(&history, ft_free_string);
	clear_history();
}

/*Main function:
	- Checks the number of arguments and prints help if they are not correct.
	- Prints the welcome message.
	- Initializes the global variable.
	- Starts the loop.
	- Frees the global memory allocated.*/
int	main(int ac, char **av, char **env)
{
	t_global	*global;
	int			laststatus;
	t_bool		devmode;

	laststatus = EXIT_SUCCESS;
	devmode = FALSE;
	if (ac >= 2)
	{
		if (ft_strequal(av[1], "--Dev") == TRUE)
			devmode = TRUE;
		else
			ft_printhelp();
	}
	ft_printwellcome();
	ft_initglobal(&global, env, devmode);
	ft_set_terminal();
	ft_loop(global);
	laststatus = global->laststatus;
	ft_freeglobal(&global);
	return (laststatus);
}
