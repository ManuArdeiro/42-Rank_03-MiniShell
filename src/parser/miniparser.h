/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniparser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:07:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/22 20:12:25 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIPARSER_H
# define MINIPARSER_H

# include "minishell.h"

typedef struct s_command
{
	char		*name;
	char		**args;
	char		*wildcards;
}				t_command;

typedef struct s_summarizer
{
	int		count;
	t_token	tokens;
}				t_summarizer;

#endif