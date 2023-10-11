/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniexecuter.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:11:58 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/11 13:04:28 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIEXECUTER_H
# define MINIEXECUTER_H

# include "ministruct.h"

int		ft_openfile(char *filename, int mode);
int		ft_executecommand(t_command *command, t_list *envlist);
void	ft_duplicate_descriptors(int *input, int *output);
void	ft_closefile(int *file_descriptor);
void	ft_execute_commandline(t_minitree *root);

#endif