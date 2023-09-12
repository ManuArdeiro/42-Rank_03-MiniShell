/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:47:53 by jolopez-          #+#    #+#             */
/*   Updated: 2023/09/12 20:13:35 by yzaytoun         ###   ########.fr       */
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
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include <signal.h>
# include "mini_struct.h"

typedef struct s_global
{
	t_bool	status;
	char	*line;
}	t_global;

//ANCHOR - 	File utils/print_msg.c
void		ft_printhelp(void);
void		ft_printwellcome(void);
void		ft_printerror(char *function, char *string);

//ANCHOR - ReadLine Functions
void		rl_clear_history(void);
void		rl_replace_line(const char *text, int clear_undo);

//ANCHOR - History
int			ft_is_validcommand(char **string);
#endif