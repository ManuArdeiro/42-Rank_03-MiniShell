/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniparser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:07:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/13 15:46:41 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIPARSER_H		/*Mini Parser*/
# define MINIPARSER_H

# include "ministruct.h"

//Summary
void		ft_print_token(t_token token);
t_list		*ft_get_unique_tokens(t_part *tokenlist);
t_list		*ft_summarize(t_part *tokenlist);
t_list		*ft_get_token_summary(t_part *tokenlist, t_list *unique_token_list);
int			ft_get_tokencount(t_list *summary, t_token token);
void		ft_printsummary(t_list *command_summary);

//Command list
t_part		*ft_get_commandlist(t_part *tokenlist, t_part *delimiter);

//Parse Tree
t_minitree	*ft_parse_commandline(const char *commandline);
t_mininode	*ft_create_mininode(void *content, t_nodetype type);
t_minitree	*ft_tokensplit(t_part *tokenlist, t_token token);
void		ft_printtree(t_minitree *root);

char		*ft_extract_tokenstring(char *line, t_part *node);
t_list		*ft_extract_stringlist(
				char *commandline, t_part *tokenlist, t_token token);
t_list		*ft_extract_filelist(
				char *commandline, t_part *tokenlist, t_bool filedirection);
t_command	*ft_createcommand(
				char *name, t_list *arglist, t_list *infile, t_list *outfile);
t_part		*ft_get_tokennode(
				t_part *tokenlist, t_token token, t_bool position);
t_nodetype	ft_get_nodetype(t_part *tokenlist);

void		ft_printcommand(t_command *command);

t_bool		ft_isseparator(t_token token);
t_bool		ft_is_logicalseparator(t_token token);
t_bool		ft_is_pipeseparator(t_token token);
t_bool		ft_is_subshellseparator(t_token token);
t_bool		ft_is_semicolon(t_token token);

//CONVERT FUNCTIONS
char		**ft_lstconvert_strarr(t_list *list);
t_file		*ft_lstconvert_filearr(t_list *list);
#endif		/*Mini Parser*/