/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ministruct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:10:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/29 20:06:13 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISTRUCT_H
# define MINISTRUCT_H

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

typedef struct s_part
{
	int				index;
	t_bool			used;
	t_token			token;
	int				start;
	int				end;
	struct s_part	*next;
}	t_part;

typedef enum s_bool
{
	EXIT = -1,
	FALSE,
	TRUE,
	OVERWRITE_VALUE,
	ADD_VALUE
}			t_bool;

typedef struct s_dict	t_dict;

struct s_dict
{
	char	*key;
	char	*value;
};

#endif