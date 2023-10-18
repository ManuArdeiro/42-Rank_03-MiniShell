/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:18:23 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/18 16:40:59 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "ministruct.h"

t_part		*ft_tokenizer(char *line, int *tk_count);
int			ft_is_space(char *line, int i);
t_part		*ft_create_tkn_list(void);
int			ft_last_index(t_part *tokens);
t_part		*ft_last_tkn(t_part *tokens);
int			ft_add_tkn(t_part *tokens, t_token token, int start, int end);
void		ft_get_tokens(char *line, t_part *tokens);
int			ft_count_tokens(char *line);
int			ft_token_1(t_part *tokens, char *line, int *i);
void		ft_tokenlist_add(t_part **tokenlist, t_part *newtoken);

t_part		*ft_copytoken(t_part *tokennode);
void		ft_tokenlist_add(t_part **tokenlist, t_part *newtoken);
void		ft_print_tokenlist(t_part *tokenlist);
void		ft_print_token(t_token token);


#endif