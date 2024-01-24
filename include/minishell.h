/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:47:53 by jolopez-          #+#    #+#             */
/*   Updated: 2024/01/24 18:41:05 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MINI_PROMPT	"\x1b\e[0;36mMiniShell $> \x1b[0m"
# define BACKSLASH		"$> "
# define PIPELINE		"pipe $> "

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "ministruct.h"
# include "miniparser.h"
# include "miniexecuter.h"
# include "tokenizer.h"
# include "termcap.h"

// Global variable (for signals)
volatile sig_atomic_t	g_exit_status;

//Signal handlers
void		handle_sigquit(int signum);
void		handle_sigint2(int signum);
void		handle_sigint_exit(int signum);
void		ft_signal_handler(int signum);
void		ft_initsignals(t_global *global);

// File utils
void		ft_printhelp(void);
void		ft_printwellcome(void);
void		ft_printerror(const char *function, const char *string);
void		ft_freeglobal(t_global **global);
void		ft_initglobal(t_global **global, char **env, t_bool devmode);
void		ft_set_terminal(void);

// Environment
void		ft_setenv(t_list **envlist, char *key, char *value, int overwrite);
char		*ft_getenv(const char *key, t_list *envlist);
t_list		*ft_initenv(char **env);
int			ft_delenv(t_list *envList, char *key);

// Built-ins
int			ft_builtins(char **args, t_list *envList, t_global *global);
int			ft_print_not_found(char *arg);
int			ft_print_not_valid(char *arg);
void		ft_print_screen(char *str);
int			ft_arg_nbr(char **args);
int			ft_mini_cd(char **arg, t_list *envList);
int			ft_mini_echo(char **args);
int			ft_mini_env(t_list *envList, char **args);
int			ft_mini_exit(t_global *global, char **args);
int			ft_mini_export(t_list *envList, char **args);
int			ft_mini_pwd(void);
int			ft_mini_unset(t_list *envList, char **args);
int			ft_clearscreen(t_list *envlist);

// Util
char		*ft_get_localpath(void);
char		*ft_get_rootpath(const char *path);
void		ft_free_string(void *content);
void		ft_print_commanderror(
				const char *commandname, const char *errortype);
char		*ft_get_completeline(const char *commandline, t_global *global);
char		*ft_completeline(
				const char *commandline, const char *prompt, int pip[2]);

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
t_minitree	*ft_get_lasttreenode(t_minitree *root, t_bool direction);
#endif