/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:47:53 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/07 21:58:10 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MINI_PROMPT	"\x1b[31mMiniShell $> \x1b[0m"

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "ministruct.h"
# include "minitree.h"
# include "miniparser.h"
# include "miniexecuter.h"

typedef struct s_global
{
	int		tk_count;
	t_bool	status;
	char	*line;
	t_list	*envlist;
}	t_global;

// File utils/print_msg.c
void		ft_printhelp(void);
void		ft_printwellcome(void);
void		ft_printerror(const char *function, const char *string);

// Tokenizer

t_part		*ft_tokenizer(char *line, int *tk_count);
int			ft_is_space(char *line, int i);
t_part		*ft_create_tkn_list(void);
int			ft_last_index(t_part *tokens);
t_part		*ft_last_tkn(t_part *tokens);
void		ft_add_tkn(t_part *tokens, t_token token, int start, int end);
void		ft_get_tokens(char *line, t_part *tokens);
int			ft_count_tokens(char *line);
void		ft_token_1(t_part *tokens, char *line, int *i);

// Built-ins

void		ft_print_screen(char *str);
int			ft_arg_nbr(char **args);
int			ft_mini_cd(char **arg, t_list *envlist);
int			ft_mini_echo(char **args);
int			ft_mini_pwd(void);
int			ft_mini_env(t_list *envList);

// ReadLine Functions
void		rl_clear_history(void);
void		rl_replace_line(const char *text, int clear_undo);

// Environment
void		ft_setenv(t_list **envlist, char *key, char *value, int overwrite);
char		*ft_getenv(const char *key, t_list *envlist);
t_list		*ft_initenv(char **env);
int			ft_printenv(t_list *envlist);

// Util
char		*ft_get_localpath(void);
char		*ft_get_rootpath(const char *path);

//History
void		ft_write_command_history(t_list **history, t_global *global);
void		ft_register_command(t_list **history, char *command);

//Dictionary
int			ft_emptydict(t_dict *dict);
void		ft_cleardict(void *content);
int			ft_searchdict(t_list *list, const char *key);
int			ft_modifydict(
				t_list **envlist, const char *key, const char *newvalue);
void		ft_add_to_dict(t_list **envlist, char *key, char *value);

//AUX
void		ft_free_string(void *content);

//PARSER
t_command	*ft_parse_line(t_token *tokens_array, int token_count);

#endif