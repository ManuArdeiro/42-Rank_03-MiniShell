/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ministruct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:10:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/25 19:04:26 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISTRUCT_H
# define MINISTRUCT_H

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

typedef enum e_token
{
	tk_lprnths = 1,
	tk_rprnths,
	tk_sglquot,
	tk_dblquot,
	tk_mul,
	tk_semi,
	tk_less,
	tk_dblless,
	tk_gtr,
	tk_dblgtr,
	tk_pipe,
	tk_or,
	tk_and,
	tk_state,
	tk_word
}	t_token;


struct s_command
{
	int		infile;
	int		outfile;
	char	*command;
};
#endif