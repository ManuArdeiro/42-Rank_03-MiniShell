/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:55:53 by jolopez-          #+#    #+#             */
/*   Updated: 2023/12/24 18:49:34 by yzaytoun         ###   ########.fr       */
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
	global->pidarray = NULL;
	global->pidcount = 0;
	g_exit_status = EXIT_SUCCESS;
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
			global->line = ft_get_completeline(global->line);
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

/*	This function first frees the list of environment strings then frees the
	global structure allocated memory.	*/

static void	ft_free(t_global **global)
{
	ft_lstclear(&((*global)->envlist), ft_cleardict);
	free(*global);
}

/*	This function inits the glogal structure variable allocating memory 
	with calloc. Then it creates the environment items list depending on
	the environment passed as argument (or not) calling to ft_initenv()
	function.	*/

static void	ft_init(
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
}

//For Debugging
//static void	ft_panic(void)
//{
	//	system("leaks minishell");
//}
/*	Main function:
	- Checks the number of arguments and prints help if they are not correct.
	- Prints the welcome message.
	- Initializes the global variable.
	- Starts the loop.
	- Frees the global memory allocated.	*/

int	main(int ac, char **av, char **env)
{
	t_global	*global;
	int			shell_level;
	int			laststatus;
	t_bool		devmode;

//	atexit(ft_panic);
	laststatus = EXIT_SUCCESS;
	devmode = FALSE;
	shell_level = 0;
	if (ac >= 2)
	{
		if (ft_isdigit(av[1][0]) == TRUE)
			shell_level = ft_atoi(av[1]);
		else if (ft_strequal(av[1], "--Dev") == TRUE)
			devmode = TRUE;
		else
			ft_printhelp();
	}
	ft_printwellcome();
	ft_init(&global, env, shell_level, devmode);
	ft_loop(global);
	laststatus = global->laststatus;
	ft_free(&global);
	return (laststatus);
}
