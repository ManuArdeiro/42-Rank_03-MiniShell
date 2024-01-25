/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniexecuter.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:11:58 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/01/24 20:29:06 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIEXECUTER_H
# define MINIEXECUTER_H

# include "libft/libft.h"
# include "ministruct.h"

int		ft_openfile(char *filename, int mode);
void	ft_open_filestreams(t_file **infile, t_file **outfile);
void	ft_duplicate_descriptors(int *input, int *output);
void	ft_closefile(int *file_descriptor);
void	ft_execute_commandline(t_minitree *root, t_global *global);
int		ft_executecommand(t_command *command, t_global *global);
int		ft_execute_pipeline(t_minitree *root, t_global *global);
char	*ft_add_pathprefix(char *commandname, char *pathvariables);
t_list	*ft_get_lstnode(t_list *lst, const char *string_tofind);

//Builtins
t_bool	ft_isbuiltin(char *commandname);
int		ft_wait_subprocess(
			t_command *command, pid_t *pid, int pidcount, t_global *global);
void	ft_execute_subprocess(t_command *command, t_file *infile,
			t_file *outfile, t_global *global);
int		ft_create_subprocess(t_command *command, pid_t **pid, t_global *global);
int		ft_evaluate_subprocess(int status, t_global *global);
void	ft_execute_builtin(
			t_command *command, pid_t *pid, t_list *node, t_global *global);
int		ft_navigate_and_execute(t_minitree *root, t_global *global);
void	ft_expand_filelist(t_list **filelist, t_global *global);
void	ft_get_heredoc(t_file **file, t_global *global);
void	ft_wait_close_heredoc(pid_t child, t_file *file,
			int *herepipe, t_global *global);

void	ft_wait_process(pid_t *pid, int *laststatus,
			t_bool processtype, t_global *global);

void	ft_handle_shelvl(t_global **global);
int		ft_is_directory(const char *path);
void	ft_terminateprocess(t_command *command, char **args,
			char **envp, const char *errortype);
int		ft_execute_subshell(t_minitree *root, t_global *global);

t_list	*ft_get_stringlist(const char *fullstring);

#endif