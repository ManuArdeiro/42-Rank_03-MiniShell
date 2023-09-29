/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ministruct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:10:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/29 18:53:00 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISTRUCT_H
# define MINISTRUCT_H

# include "libft.h"

typedef struct s_dict		t_dict;
typedef struct s_command	t_command;

typedef enum s_bool
{
	EXIT = -1,
	FALSE,
	TRUE,
	OVERWRITE_VALUE,
	ADD_VALUE
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
	tk_arg
}	t_token;


struct s_command
{
	int		*infile;
	int		*outfile;
	char	*name;
	char	**args;
};

typedef struct s_part
{
	int		index;
	int		token;
	int		start;
	int		end;
	t_part	*next;
}	t_part;

typedef struct s_summarizer
{
	int		count;
	t_token	token;
}				t_summarizer;

#endif