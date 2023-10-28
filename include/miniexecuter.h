/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniexecuter.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:11:58 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/28 11:00:08 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIEXECUTER_H
# define MINIEXECUTER_H

# include "libft/libft.h"
# include "ministruct.h"

int		ft_openfile(char *filename, int mode);
void	ft_duplicate_descriptors(int *input, int *output);
void	ft_closefile(int *file_descriptor);
void	ft_execute_commandline(t_minitree *root, t_global *global);
int		ft_executecommand(t_command *command, t_global *global);

//void	ft_goto_childnode(t_minitree *root, t_bool childnode, t_global *global);
void	ft_add_pipeline(t_minitree *root);
char	*ft_add_pathprefix(char *commandname, char *pathvariables);

//Builtins
t_bool	ft_isbuiltin(char *commandname);

int		ft_wait_subprocess(pid_t *pid, int pidcount);
void	ft_execute_subprocess(t_command *command, t_file *infile,
			t_file *outfile, t_global *global);
int		ft_create_subprocess(t_command *command, pid_t **pid, t_global *global);
int		ft_evaluate_subprocess(int status);
#endif