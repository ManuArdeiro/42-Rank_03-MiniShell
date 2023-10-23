/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:47:53 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/23 19:25:13 by yzaytoun         ###   ########.fr       */
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
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "ministruct.h"
# include "miniparser.h"
# include "miniexecuter.h"
# include "tokenizer.h"

typedef struct s_global
{
	t_bool	status;
	char	*line;
	t_list	*envlist;
	int		laststatus;
}	t_global;

// Signals


// File utils/print_msg.c
void		ft_printhelp(void);
void		ft_printwellcome(void);
void		ft_printerror(const char *function, const char *string);

// ReadLine Functions
void		rl_clear_history(void);
void		rl_replace_line(const char *text, int clear_undo);

// Environment
void		ft_setenv(t_list **envlist, char *key, char *value, int overwrite);
char		*ft_getenv(const char *key, t_list *envlist);
t_list		*ft_initenv(char **env);
int			ft_printenv(t_list *envlist);
int			ft_delenv(t_list *envList, char *key);

// Built-ins

int			ft_builtins(char **args, t_list *envList, t_global *global);
void		ft_print_screen(char *str);
int			ft_arg_nbr(char **args);
int			ft_mini_cd(char **arg, t_list *envList);
int			ft_mini_echo(char **args);
int			ft_mini_env(t_list *envList);
int			ft_mini_exit(t_global *global, char **args);
int			ft_mini_export(t_list *envList, char **args);
int			ft_mini_pwd(void);
int			ft_mini_unset(t_list *envList, char **args);

// Util
char		*ft_get_localpath(void);
char		*ft_get_rootpath(const char *path);
void		ft_free_string(void *content);
void		ft_get_commandhistory(t_list *envlist);

//History
void		ft_write_command_history(t_list **history, t_global *global);
void		ft_register_command(t_list **history, char *command);

//Mini Dictionary
int			ft_emptydict(t_dict *dict);
void		ft_cleardict(void *content);
int			ft_searchdict(t_list *list, const char *key);
int			ft_modifydict(
				t_list **envlist, const char *key, const char *newvalue);
void		ft_add_to_dict(t_list **envlist, char *key, char *value);

//FIXME - DELETE BEFORE MERGE
int			ft_builtins(char **args, t_list *envList, t_global *global);
#endif