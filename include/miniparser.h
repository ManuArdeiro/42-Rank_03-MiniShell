/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniparser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:07:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/29 19:15:29 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIPARSER_H
# define MINIPARSER_H

# include "ministruct.h"

//Summary
void		ft_print_token(t_token token);
t_list		*ft_get_unique_tokens(t_part *tokenlist);
t_list		*ft_summarize(t_part *tokenlist);
t_list		*ft_get_token_summary(t_part *tokenlist, t_list *unique_token_list);
int			ft_get_token_count(t_list *summary, t_token token);


void		ft_printsummary(t_list *command_summary);

//Minitree
t_command	*ft_createcommand(char *name, char *arg, int infile, int outfile);

#endif