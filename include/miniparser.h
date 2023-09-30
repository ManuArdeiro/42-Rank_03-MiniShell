/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniparser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:07:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/30 19:24:24 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIPARSER_H		/*Mini Parser*/
# define MINIPARSER_H

# include "ministruct.h"

//Summary
void		ft_print_token(t_token token);
t_list		*ft_get_unique_tokens(t_part *tokenlist);
t_list		*ft_summarize(t_part *tokenlist);
t_list		*ft_get_token_summary(t_part *tokenlist, t_list *unique_token_list);
int			ft_get_token_count(t_list *summary, t_token token);


void		ft_printsummary(t_list *command_summary);

//Command Tree
char		*ft_extract_tokenstring(char *line, t_part *node);
t_command	*ft_createcommand(
				char *name, t_list *arglist, t_list *infile, t_list *outfile);
t_part		*ft_get_tokennode(t_part *tokenlist, t_token token);

//AUX FINCTIONS
t_bool		ft_isseparator(t_token token);


//CONVERT FUNCTIONS
char		**ft_lst_to_strarr(t_list *list);


#endif		/*Mini Parser*/