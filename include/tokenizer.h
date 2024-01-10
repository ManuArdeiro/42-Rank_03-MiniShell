/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:18:23 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/10 19:14:47 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "ministruct.h"

t_part		*ft_tokenizer(t_global *global, int *tk_count);
int			ft_is_space(char *line, int i);
t_part		*ft_create_tkn_list(void);
int			ft_last_index(t_part *tokens);
t_part		*ft_last_tkn(t_part *tokens);
int			ft_add_tkn(t_part *tokens, t_token token, int start, int end);
void		ft_del_last_tkn(t_part *tokens);
void		ft_get_tokens(char *line, t_part *tokens);
int			ft_count_tokens(char *line);
void		ft_avoid_quots(t_global *global);
int			ft_token_1(t_part *tokens, char *line, int *i);
void		ft_tokenlist_add(t_part **tokenlist, t_part *newtoken);

t_part		*ft_copytoken(t_part *tokennode);
void		ft_tokenlist_add(t_part **tokenlist, t_part *newtoken);
void		ft_print_tokenlist(t_part *tokenlist);
void		ft_print_token(t_token token);

void		ft_free_tokenlist(t_part **tokenlist);
t_part		*ft_get_lasttoken(t_part *tokenlist);
void		ft_reverse_tokenlist(t_part **tokenlist);
t_part		*ft_get_token_byindex(t_part *tokenlist, t_part *token_tofind);
void		ft_add_cmdtoken(const char *line, t_part *tokens, int *i);
void		ft_evaluatetoken(t_part *tokens, char *line, int *i, int *ok);
#endif