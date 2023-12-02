/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:47:53 by jolopez-          #+#    #+#             */
/*   Updated: 2023/12/02 19:42:04 by jolopez-         ###   ########.fr       */
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

t_signals	g_signals;

// Signals
void		ft_signals(void);
void		ft_sig_int(int sig_num);
void		ft_sig_quit(int sig_num);

// File utils/print_msg.c
void		ft_printhelp(void);
void		ft_printwellcome(void);
void		ft_printerror(const char *function, const char *string);

// Environment
void		ft_setenv(t_list **envlist, char *key, char *value, int overwrite);
char		*ft_getenv(const char *key, t_list *envlist);
t_list		*ft_initenv(char **env, int shell_level);
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
int			ft_clearscreen(t_list *envlist);

// Util
char		*ft_get_localpath(void);
char		*ft_get_rootpath(const char *path);
void		ft_free_string(void *content);
void		ft_print_commanderror(const char *commandname);
char		*ft_get_completeline(const char *commandline);

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