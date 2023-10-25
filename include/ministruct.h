/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ministruct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:10:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/23 20:01:51 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISTRUCT_H	/*Mini struct header*/
# define MINISTRUCT_H

# include "libft.h"
# include "minitree.h"

typedef struct s_dict			t_dict;
typedef struct s_command		t_command;
typedef struct s_file			t_file;
typedef enum e_bool				t_bool;
typedef enum e_token			t_token;
typedef enum e_nodetype			t_nodetype;
typedef struct s_summarizer		t_summarizer;
typedef struct s_part			t_part;
typedef struct s_mininode		t_mininode;
typedef enum e_casttype			t_casttype;

enum e_casttype
{
	TYPE_STRING,
	TYPE_FILE,
	TYPE_COMMAND,
	TYPE_LIST
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
	NEXT_NODE,
	CURRENT_NODE
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
	tk_lprnths,
	tk_rprnths,
	tk_sglquot,
	tk_dblquot,
	tk_pipe,
	tk_mul,
	tk_semi,
	tk_less,
	tk_dblless,
	tk_grt,
	tk_dblgrt,
	tk_ampersand,
	tk_doll_exc,
	tk_dollar,
	tk_cmd,
	tk_arg,
	tk_equal,
	tk_newline,
	max_token
};

struct s_file	/*File desciptor and name*/
{
	char	*name;
	int		fd;
};

struct s_command
{
	char	*name;
	char	**args;
	t_file	*infile;
	t_file	*outfile;
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
	n_and_or = 10,
	n_pipeline,
	n_command,
	n_commandlist,
	n_subshell
};

struct s_mininode
{
	t_nodetype	type;
	void		*content;
};

#endif		/*Mini struct header*/