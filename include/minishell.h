/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:47:53 by jolopez-          #+#    #+#             */
/*   Updated: 2023/09/26 20:03:41 by jolopez-         ###   ########.fr       */
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
# include "libft.h"
# include <signal.h>
# include "ministruct.h"

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

// File utils/tools.c
int			ft_is_space(char *line, int *i);

// Tokenizer

t_token		*ft_tokenizer(char *line, int *tk_number);
void		ft_token_1(t_token *tokens, char *line, int *i, int *j);
void		ft_token_2(t_token *tokens, char *line, int *i, int *j);
void		ft_token_3(t_token *tokens, char *line, int *i, int *j);
void		ft_token_4(t_token *tokens, char *line, int *i, int *j);
void		ft_token_5(t_token *tokens, char *line, int *i, int *j);
void		ft_token_6(t_token *tokens, char *line, int *i, int *j);
void		ft_get_tokens(char *line, t_token *tokens, int *i, int *j);
int			ft_count_tokens(char *line);
int			ft_is_space(char *line, int *i);

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
#endif