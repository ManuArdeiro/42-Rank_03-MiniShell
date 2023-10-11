/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:55:53 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/11 13:05:20 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_register_and_clean(t_list **history, t_global **global)
{
	if ((*global)->line && (*global)->line[0] != 32)
	{
		ft_register_command(history, (*global)->line);
		add_history((*global)->line);
	}
	if ((*global)->line)
	{
		free((*global)->line);
		(*global)->line = NULL;
	}
}

/*	The loop will be running continuously as long as "exit" is not written on 
	the command line: 
	-	It will read every phrase typed on the command line (using readline()
	function and will pass it to the tokenizer to recognize the diffetent tokens.
	-	Then will call the parser.
	-	
	

Por qué if (!global->line)
			break ;?

	*/

static void	ft_loop(t_global *global)
{
	t_list		*history;
	t_minitree	*parsetree;

	history = NULL;
	while (global->status != EXITED)
	{
		global->line = readline(MINI_PROMPT);
		if (!global->line)
			break ;
		if (ft_strncmp(global->line, "exit", 4) == 0)
			global->status = EXITED;
		parsetree = ft_parse_commandline(global->line);
		//ft_execute_commandline(parsetree);
		ft_destroytree(&parsetree);
		ft_register_and_clean(&history, &global);
	}
	rl_clear_history();
	ft_write_command_history(&history, global);
	ft_lstclear(&history, ft_free_string);
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

static void	ft_init(t_global **global, char **env)
{
	*global = ft_calloc(sizeof(t_global), 1);
	if (*global == NULL)
		return ;
	(*global)->envlist = ft_initenv(env);
}

//For Debugging
/*static void	ft_panic(void)
{
	system("leaks minishell");
}
*/

/*	Main function:
	- Checks the number of arguments and prints help if they are not correct.
	- Prints the welcome message.
	- Initializes the global variable.
	- Starts the loop.
	- Frees the global memory allocated.	*/

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
	ft_loop(global);
	ft_free(&global);
	return (EXIT_SUCCESS);
}
