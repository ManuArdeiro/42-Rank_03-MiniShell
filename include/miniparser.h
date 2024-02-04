/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniparser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:07:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/04 18:10:46 by yzaytoun         ###   ########.fr       */
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
void		ft_clearsummary(void *content);

//Parse Tree
void		ft_printnode(t_mininode *mininode);
void		ft_free_mininode(void *content);
t_bool		ft_is_emptynode(t_minitree *root);
t_minitree	*ft_parse_commandline(t_global *global);
t_mininode	*ft_create_mininode(void *content, t_nodetype type);
t_minitree	*ft_tokensplit(t_part *tokenlist, t_token token);
t_part		*ft_get_tokennode(t_part *tokenlist, t_token token,
				t_bool strict, t_bool direction);
t_nodetype	ft_get_nodetype(t_part *tokenlist);
t_bool		ft_isvalid_commandlist(t_part *tokenlist);
t_bool		ft_is_tokenpair(t_token token);
t_bool		ft_validate_tokenlist(t_part *tokenlist);
t_token		ft_get_tokenpair(t_token token);
t_minitree	*ft_split_subshell(t_part *tokenlist, t_global *global);
t_minitree	*ft_split_tokenlist(t_part *tokenlist);
t_bool		ft_valid_subshellnode(t_part *tokenlist);
t_part		*ft_skip_tokens(t_part *token, t_bool (*skipfunction)(t_token));
t_bool		ft_tokenlist_contains(
				t_part *tokenlist, t_bool (*function)(t_token token));
t_bool		ft_contains_sub_tokenlist(
				t_part *startnode, t_part *endnode, t_token token);
t_part		*skip_get_tokennode(
				t_part *tokenlist, t_token token_tofind, t_bool strict);
t_bool		is_complete_subshell(t_part *tokenlist);

//Command list
t_bool		ft_is_command(t_token token);
t_part		*ft_copy_tokenlist(t_part *tokenlist, t_part *delimiter);
t_minitree	*ft_get_minicommand(t_part *tokenlist, t_global *global);
void		ft_printcommand(t_command *command);
t_bool		ft_is_compoundcommand(t_nodetype nodetype);
char		*ft_extract_tokenstring(const char *commandline, t_part *node);
t_list		*ft_extract_arglist(t_part *tokenlist, t_global *global);
void		ft_free_commandlist(t_command **command);
t_list		*ft_clear_emptyvalues(t_list *list);
char		*ft_get_commandseries(
				t_part *seriesstart, t_part *seriesend, t_global *global);
void		ft_checkquotes(char **string);
t_bool		ft_isvalid_series(t_part *node);
void		ft_set_tokenlist(
				t_part **tokenlist, t_part *delimiter, t_bool newstate);
char		*ft_extractseries(t_part *tokenlist, t_global *global);
t_part		*ft_get_last_seriestoken(t_part *tokenlist);
t_part		*ft_fastforward(t_part *tokenlist);
t_bool		ft_is_emptyquotes(t_part *startnode, t_part *endnode);
t_bool		ft_token_case(t_part *head);
t_bool		ft_get_stringpart(const char *pathsuffix);
t_part		*ft_skip_quotes(t_part *tokenlist, t_token token);
t_part		*ft_copy_tokenlist_ex(t_part *tokenlist, t_part *delimiter);
t_bool		ft_is_backslash_token(t_token token);

//File
t_part		*ft_skip_redirection(t_part *tokenlist);
t_list		*ft_extract_filelist(
				t_part *tokenlist, t_bool filedirection, t_global *global);
t_file		*ft_create_file(const char *name, int std_stream, int mode);
int			ft_get_filemode(t_token token);
t_bool		ft_is_redirection(t_token token);
void		ft_freefile(void *content);
t_file		*ft_compress_filelist(t_list *filelist, t_global *global);
void		ft_delete_filenode(t_list **filelist, char *file_todelete);
void		ft_clone_streams(int *inputclone, int *outputclone);
void		ft_closepipe(int *input, int *output);
t_list		*ft_default_filelist(int std_stream);
char		*ft_extract_dollarstring(
				const char *commandline, t_part *tokenlist);
t_bool		ft_is_dollar(t_token token);

//Separators
t_bool		ft_is_tokenseparator(t_token token);
t_bool		ft_is_logicalseparator(t_token token);
t_bool		ft_is_pipeseparator(t_token token);
t_bool		ft_is_subshellseparator(t_token token);
t_bool		ft_is_semicolon(t_token token);

//Expansions
t_list		*ft_expand_startoken(const char *fullpath);
char		*ft_expand_dollartoken(const char *argument, t_global *global);
char		*ft_get_starstring(t_part **tokenlist, t_global *global);
char		*ft_expandstring(t_global *global, t_part *startnode,
				t_part *endnode, t_cleancase cleancase);
t_bool		ft_emptystring(const char *string);

//CONVERT FUNCTIONS
char		**ft_lstconvert_strarr(t_list *list, t_bool type);
#endif		/*Mini Parser*/