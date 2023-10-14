/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniparser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:07:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/14 19:01:58 by yzaytoun         ###   ########.fr       */
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
int			ft_filelist_size(t_file *filelist);
void		ft_printnode(t_mininode *mininode);
void		ft_free_mininode(void *content);
t_bool		ft_is_emptynode(t_minitree *root);
t_minitree	*ft_parse_commandline(const char *commandline);
t_mininode	*ft_create_mininode(void *content, t_nodetype type);
t_minitree	*ft_tokensplit(t_part *tokenlist, t_token token);

char		*ft_extract_tokenstring(const char *commandline, t_part *node);
t_list		*ft_extract_stringlist(
				const char *commandline, t_part *tokenlist, t_token token);
t_list		*ft_extract_filelist(
				const char *commandline,
				t_part *tokenlist, t_bool filedirection);
t_part		*ft_get_tokennode(
				t_part *tokenlist, t_token token, t_bool position);
t_nodetype	ft_get_nodetype(t_part *tokenlist);

//Separators
t_bool		ft_isseparator(t_token token);
t_bool		ft_is_logicalseparator(t_token token);
t_bool		ft_is_pipeseparator(t_token token);
t_bool		ft_is_subshellseparator(t_token token);
t_bool		ft_is_semicolon(t_token token);

//CONVERT FUNCTIONS
char		**ft_lstconvert_strarr(t_list *list);
t_file		*ft_lstconvert_filearr(t_list *list, int std_stream);
#endif		/*Mini Parser*/