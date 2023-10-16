/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniexecuter.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:11:58 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/16 19:50:40 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIEXECUTER_H
# define MINIEXECUTER_H

# include "libft/libft.h"
# include "ministruct.h"

int		ft_openfile(char *filename, int mode);
t_bool	ft_executecommand(t_command *command, char **envp);
void	ft_duplicate_descriptors(int *input, int *output);
void	ft_closefile(int *file_descriptor);
void	ft_execute_commandline(t_minitree *root, t_list *envlist);


int		ft_goto_childnode(t_minitree *root, char **envp, t_bool childnode);
int		ft_execute_pipeline(t_mininode *mininode, char **envp);
char	*ft_add_pathprefix(char *commandname, t_list *envlist);

#endif