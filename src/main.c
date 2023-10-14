/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:55:53 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/14 19:24:47 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_print_tokens(t_token print)
{
	if (print == tk_lprnths)
		printf("valor = %s\n", "tk_lprnths");
	if (print == tk_rprnths)
		printf("valor = %s\n", "tk_rprnths");
	if (print == tk_sglquot)
		printf("valor = %s\n", "tk_sglquot");
	if (print == tk_dblquot)
		printf("valor = %s\n", "tk_dblquot");
	if (print == tk_mul)
		printf("valor = %s\n", "tk_mul");
	if (print == tk_semi)
		printf("valor = %s\n", "tk_semi");
	if (print == tk_less)
		printf("valor = %s\n", "tk_less");
	if (print == tk_dblless)
		printf("valor = %s\n", "tk_dblless");
	if (print == tk_grt)
		printf("valor = %s\n", "tk_grt");
	if (print == tk_dblgrt)
		printf("valor = %s\n", "tk_dblgrt");
	if (print == tk_pipe)
		printf("valor = %s\n", "tk_pipe");
	if (print == tk_or)
		printf("valor = %s\n", "tk_or");
	if (print == tk_ampersand)
		printf("valor = %s\n", "tk_ampersand");
	if (print == tk_and)
		printf("valor = %s\n", "tk_and");
	if (print == tk_doll_exc)
		printf("valor = %s\n", "tk_doll_exc");
	if (print == tk_dollar)
		printf("valor = %s\n", "tk_dollar");
	if (print == tk_cmd)
		printf("valor = %s\n", "tk_cmd");
	if (print == tk_arg)
		printf("valor = %s\n", "tk_arg");
}

/*	This function register the lines wrote in the command line in a
	file called ./minishell_history in the HOME directory and clean the
	line in the global structure.	*/
	
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
		function and will pass it to the tokenizer to recognize the diffetent
		tokens.
	-	Then will call the parser.
	-	
	*/

static int	ft_loop(t_global *global)
{
	t_list	*history;
	t_part	*tokens;
	t_part	*print;

	history = NULL;
	while (global->status != EXITED)
	{
		global->line = readline(MINI_PROMPT);
		if (!global->line)
			ft_printerror(__func__, "Error reading line (readline function).") ;
		if (ft_strncmp(global->line, "exit", 4) == 0)
			global->status = EXITED;
		tokens = ft_tokenizer(global->line, &global->tk_count);
		print = tokens;
			while (print)
			{
				printf("token %d = %d\t", print->index, print->token);
				ft_print_tokens(print->token);
				print = print->next;
			}
		//parser
		ft_register_and_clean(&history, &global);
	}
	//rl_clear_history();
	ft_write_command_history(&history, global);
	ft_lstclear(&history, ft_free_string);
	return (EXIT_SUCCESS);
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
	if (ft_loop(global) != EXIT_SUCCESS)
		perror("Error using minishell");
	ft_free(&global);
	return (EXIT_SUCCESS);
}
