/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ministruct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:10:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/29 18:09:02 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISTRUCT_H	/*Mini struct header*/
# define MINISTRUCT_H

# include "libft.h"
# include "minitree.h"
# include <termios.h>

# define PERMISSION_DENIED 	" Permission denied : "
# define STAR 				" no matches found : "
# define IS_DIRECTORY		" is a directory : "
# define NO_SUCH_FILE_OUT	"out"
# define NO_SUCH_FILE_IN	"in"
# define NO_SUCH_FILE		" no such file or directory : "
# define COMMAND_NOT_FOUND	" command not found : "

typedef struct s_global			t_global;
typedef struct s_dict			t_dict;
typedef struct s_command		t_command;
typedef struct s_file			t_file;
typedef enum e_bool				t_bool;
typedef enum e_token			t_token;
typedef enum e_nodetype			t_nodetype;
typedef struct s_summarizer		t_summarizer;
typedef struct s_part			t_part;
typedef struct s_mininode		t_mininode;
typedef enum e_cleancase		t_cleancase;
typedef struct sigaction		t_sigaction;
typedef struct termios			t_termios;

enum e_cleancase
{
	CLEAN_ALL_LEAVE_PIPE,
	CLEAN_ALL,
	CLEAN_QUOTES,
	CLEAN_SINGLE_QUOTES,
	CLEAN_DOUBLE_QUOTES,
	CLEAN_EMPTY_QUOTES
};

enum e_bool
{
	EXITED = -1,
	FALSE,
	TRUE,
	OVERWRITE_VALUE,
	ADD_VALUE,
	INFILE,
	OUTFILE,
	LEFT,
	RIGHT,
	PREV_NODE,
	CURRENT_NODE,
	O_HEREDOC,
	FORK,
	BUILTIN,
	FIRST,
	LAST,
	ENV,
	COPY,
	CLOSE,
	CASE_1,
	CASE_2,
	CASE_3,
	CASE_4
};

struct s_dict
{
	char	*key;
	char	*value;
};

enum e_token
{
	tk_and = 1,
	tk_or,
	tk_sglquot,
	tk_dblquot,
	tk_lprnths,
	tk_rprnths,
	tk_pipe,
	tk_mul,
	tk_semi,
	tk_less,
	tk_dblless,
	tk_grt,
	tk_dblgrt,
	tk_ampersand,
	tk_doll_int,
	tk_dollar,
	tk_cmd,
	tk_arg,
	tk_equal,
	tk_newline,
	tk_file,
	tk_space,
	max_token,
};

struct s_file	/*File desciptor and name*/
{
	char	*name;
	int		fd;
	int		mode;
};

struct s_command
{
	char	*name;
	t_list	*args;
	t_list	*infile;
	t_list	*outfile;
};

struct s_part
{
	int		index;
	t_token	token;
	int		start;
	int		end;
	t_bool	used;
	t_part	*next;
};

struct s_summarizer
{
	int		count;
	t_token	token;
};

enum e_nodetype
{
	n_and = 10,
	n_or,
	n_pipeline,
	n_command,
	n_commandlist,
	n_subshell,
	n_empty,
	n_subshellcommand
};

struct s_mininode
{
	t_nodetype	type;
	void		*content;
};

struct s_global
{
	t_bool			status;
	char			*line;
	t_list			*envlist;
	int				laststatus;
	t_nodetype		lastnodetype;
	int				shell_level;
	t_bool			expand_dollartoken;
	t_bool			expand_startoken;
	t_bool			devmode;
	int				pidcount;
	pid_t			*pidarray;
	t_sigaction		signallist;
	t_bool			subshell;
	t_bool			fileflag;
};

#endif		/*Mini struct header*/