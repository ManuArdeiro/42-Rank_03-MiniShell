/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ministruct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:10:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/07 16:58:29 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISTRUCT_H	/*Mini struct header*/
# define MINISTRUCT_H

# include "libft/libft.h"

typedef struct s_dict		t_dict;
typedef struct s_command	t_command;
typedef struct s_file		t_file;

typedef enum s_bool
{
	EXITED = -1,
	FALSE,
	TRUE,
	OVERWRITE_VALUE,
	ADD_VALUE,
	INFILE,
	OUTFILE,
}			t_bool;


struct s_dict
{
	char	*key;
	char	*value;
};

typedef enum s_token
{
	tk_lprnths = 1,
	tk_rprnths,
	tk_sglquot,
	tk_dblquot,
	tk_mul,
	tk_semi,
	tk_less,
	tk_dblless,
	tk_grt,
	tk_dblgrt,
	tk_pipe,
	tk_or,
	tk_ampersand,
	tk_and,
	tk_doll_exc,
	tk_dollar,
	tk_cmd,
	tk_arg,
	/*Add equal sign */
	/*Add newline sign */
}	t_token;

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

typedef struct s_part
{
	int				index;
	int				token;
	int				start;
	int				end;
	t_bool			used;
	struct s_part	*next;
}	t_part;

typedef struct s_summarizer
{
	int		count;
	t_token	token;
}				t_summarizer;

#endif		/*Mini struct header*/