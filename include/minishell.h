/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:47:53 by jolopez-          #+#    #+#             */
/*   Updated: 2023/09/16 18:47:08 by yzaytoun         ###   ########.fr       */
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
# include "mini_struct.h"

typedef struct s_global
{
	t_bool	status;
	char	*line;
	t_list	*envlist;
}	t_global;

// File utils/print_msg.c
void		ft_printhelp(void);
void		ft_printwellcome(void);
void		ft_printerror(const char *function, const char *string);

// ReadLine Functions
void		rl_clear_history(void);
void		rl_replace_line(const char *text, int clear_undo);

// Environment
int			ft_check_name_in_dict(t_list *envlist, const char *name);
void		ft_cleardict(void *content);
void		ft_setenv(t_list **envlist, char *name, char *value, int overwrite);
char		*ft_getenv(const char *name, t_list *envlist);
t_list		*ft_initenv(char **env);

// Util
char		*ft_get_localpath(void);
char		*ft_get_rootpath(const char *path);

//History
void		ft_write_command_history(t_list **history, t_global *global);
void		ft_register_command(t_list **history, char *command);

#endif