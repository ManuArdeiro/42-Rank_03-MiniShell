/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniparser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:07:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/27 18:06:56 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIPARSER_H
# define MINIPARSER_H

# include "minishell.h"

typedef struct s_summarizer
{
	int		count;
	t_token	token;
}				t_summarizer;

//Summary
void		ft_print_token(t_token token);
t_list		*ft_get_unique_tokens(t_token *tokens_list, int token_count);
t_list		*ft_summarize(t_token *token_list, int token_count);
t_list		*ft_get_token_summary(t_token *token_list, int token_count,
				t_list *unique_token_list);
int			ft_get_token_count(t_list *summary, t_token token);


void		ft_printsummary(t_list *command_summary);

//Minitree
t_command	*ft_createcommand(char *name, char *arg, int infile, int outfile);

#endif