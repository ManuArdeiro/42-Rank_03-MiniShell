/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniparser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:07:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/24 20:36:02 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIPARSER_H		/*Mini Parser*/
# define MINIPARSER_H

# include "ministruct.h"

//Summary
t_list		*ft_get_unique_tokens(t_part *tokenlist);
t_list		*ft_summarize(t_part *tokenlist);
t_list		*ft_get_token_summary(t_part *tokenlist, t_list *unique_token_list);
int			ft_get_tokencount(t_list *summary, t_token token);
void		ft_printsummary(t_list *command_summary);

//Command list
t_part		*ft_get_commandlist(t_part *tokenlist, t_part *delimiter);
t_minitree	*ft_get_minicommand(const char *commandline, t_part *tokenlist);
void		ft_printcommand(t_command *command);

//Parse Tree
t_bool		ft_is_compoundcommand(t_nodetype nodetype);
t_bool		ft_is_redirection(t_token token);
void		ft_printnode(t_mininode *mininode);
void		ft_free_mininode(void *content);
t_bool		ft_is_emptynode(t_minitree *root);
t_minitree	*ft_parse_commandline(const char *commandline);
t_mininode	*ft_create_mininode(void *content, t_nodetype type);
t_minitree	*ft_tokensplit(t_part *tokenlist, t_token token);

char		*ft_extract_tokenstring(const char *commandline, t_part *node);
t_list		*ft_extract_argumentlist(
				const char *commandline, t_part *tokenlist);
t_list		*ft_extract_filelist(
				const char *commandline,
				t_part *tokenlist, t_bool filedirection);
t_part		*ft_get_tokennode(
				t_part *tokenlist, t_token token, t_bool position);
t_nodetype	ft_get_nodetype(t_part *tokenlist);
t_file		*ft_create_file(const char *name, int std_stream, int mode);
int			ft_get_filemode(t_token token);

//Separators
t_bool		ft_isseparator(t_token token);
t_bool		ft_is_logicalseparator(t_token token);
t_bool		ft_is_pipeseparator(t_token token);
t_bool		ft_is_subshellseparator(t_token token);
t_bool		ft_is_semicolon(t_token token);

//Expansions
t_list		*ft_expand_startoken(char *fullpath);
char		*ft_expand_dollartoken(
				const char *argument, t_list *envlist, int laststatus);

//CONVERT FUNCTIONS
char		**ft_lstconvert_strarr(t_list *list);
//t_file		*ft_lstconvert_filearr(t_list *list, int std_stream);
#endif		/*Mini Parser*/