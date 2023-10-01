/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ministruct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:10:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/01 19:02:43 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISTRUCT_H	/*Mini struct header*/
# define MINISTRUCT_H

# include "libft.h"

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


struct s_file	/*File desciptor and name*/
{
	char	*name;
	int		fd;
};


struct s_command
{
	t_file	*infile;
	t_file	*outfile;
	char	*name;
	char	**args;
};

typedef struct s_part
{
	int		index;
	int		token;
	int		start;
	int		end;
	t_bool	used;
	t_part	*next;
}	t_part;

typedef struct s_summarizer
{
	int		count;
	t_token	token;
}				t_summarizer;

#endif		/*Mini struct header*/