/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:18:23 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/10 11:24:04 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "ministruct.h"

t_part	*ft_copytoken(t_part *tokennode);
void	ft_tokenlist_add(t_part **tokenlist, t_part *newtoken);

#endif