/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniexecuter.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:11:58 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/01 18:35:27 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIEXECUTER_H
# define MINIEXECUTER_H

# include "ministruct.h"

int		ft_openfile(char *filename, int mode);
void	ft_executecommand(t_command *command, t_list *envlist);
void	ft_duplicate_descriptors(int *input, int *output);

void	ft_executecommand(t_command *command, t_list *envlist);
t_bool	ft_execute(char *commandname, char **args, t_list *envlist);
void	ft_eval_processstatus(int status);

#endif