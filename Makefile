# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/01 18:51:45 by jolopez-          #+#    #+#              #
#    Updated: 2024/02/04 14:27:44 by jolopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 			=	minishell

vpath 			%.h	include
vpath 			%.c	src : src/cmd/built_ins : src/cmd : src/env : src/exec \
				: src/lexer : src/minitree : src/summarizer : src/utils
vpath			%.c src/parser : src/parser/command : src/parser/file
vpath 			%.o	obj

USER			= $(shell whoami)
INCLUDE 		= -Iinclude/
INC_LIB 		= -Iinclude/libft
#READLINE_LIB	= -I/Users/$(USER)/.brew/opt/readline/include
#INC_READLINE	= -L/Users/$(USER)/.brew/opt/readline/lib
INC_READLINE	= -L/usr/local/opt/readline/lib
READLINE_LIB	= -I/usr/local/opt/readline/include
SANITIZER		= -g3 -fsanitize=address -g

READLINE_FLAGS	= -lreadline -ltermcap

#-------------------------- C Files -------------------------------------
ENV				= ft_getenv.c ft_setenv.c ft_initenv.c ft_delenv.c

UTILS			= print_msg.c mini_history.c get_path.c free_string.c \
					mini_dictionary.c signals.c clearscreen.c get_completeline.c\
					init_global.c set_terminal.c completeline.c

LEXER			= tokenizer.c tokens.c token_tools_1.c token_tools_2.c \
					ft_copy_tokenlist.c ft_tokenlist_add.c print_tokenlist.c \
					add_tkn.c free_tokenlist.c get_lasttoken.c reverse_tokenlist.c\
					get_token_byindex.c avoid_quots.c ft_add_cmdtoken.c \
					del_last_token.c evaluate_token.c

COMMAND			= extract_tokenstring.c copy_tokenlist.c lstconvert.c \
					printcommand.c extract_filelist.c get_minicommand.c \
					extract_arglist.c is_compoundcommand.c free_commandlist.c\
					is_command.c clear_emptyvalues.c \
					get_commandseries.c get_last_seriestoken.c\
					checkquotes.c is_validseries.c set_tokenlist.c \
					extractseries.c fastforward.c is_emptyquotes.c\
					skip_redirection.c extract_dollarstring.c \
					token_case.c get_starstring.c get_stringpart.c\
					is_backslash_token.c
				
FILE			= filestreams.c create_file.c get_filemode.c is_redirection.c \
					freefile.c append_filecontent.c delete_filenode.c closepipe.c\
					default_filelist.c is_dollar.c

PARSER			=  separators.c get_tokennode.c tokensplit.c get_nodetype.c \
					parse_commandline.c $(COMMAND) $(FILE) isvalid_commandlist.c \
					tokenpairs.c get_tokenpair.c tokenlist_contains.c split_subshell.c\
					split_tokenlist.c valid_subshellnode.c skip_tokens.c validate_tokenlist.c\
					contains_sub_tokenlist.c skip_get_tokennode.c is_complete_subshell.c\
					expandstring.c emptystring.c skip_quotes.c
					
SUMMARIZER		= minisummary.c printtokens.c get_unique_tokens.c \
					get_token_summary.c get_token_count.c clearsummary.c
					
CMD				= mini_cd.c mini_echo.c mini_env.c mini_exit.c mini_export.c \
					mini_pwd.c mini_unset.c mini_builtins.c is_builtin.c
					
TREE 			= minitree.c treetraversal.c is_emptynode.c create_mininode.c \
				print_tree.c get_lasttreenode.c free_mininode.c
					
EXEC			= executecommand.c execute_commandline.c \
				goto_childnode.c add_pathprefix.c evaluate_subprocess.c \
				wait_subprocess.c create_subprocess.c execute_subprocess.c \
				expand_startoken.c expand_dollartoken.c execute_builtin.c \
				mini_heredoc.c expand_filelist.c execute_pipeline.c wait_close_heredoc.c \
				get_lstnode.c executer_aux.c execute_subshell.c get_stringlist.c\
				get_directorylist.c check_filepermissions.c

SRC 			= $(ENV) $(UTILS) $(SUMMARIZER) $(LEXER) \
					$(CMD) $(PARSER) $(TREE) $(EXEC)  main.c

OBJS			=	$(SRC:%.c=$(OBJ_DIR)/%.o)

RM 				=	/bin/rm -rf
CC 				= 	gcc
CFLAGS 			= 	-Wall -Werror -Wextra $(INCLUDE) $(INC_LIB) $(READLINE_LIB) -g 

LIBFT			= 	include/libft/libft.a
LIBFTDIR		= 	include/libft
OBJ_DIR			=	obj

.SILENT:
$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(@D)
	$(COMPILE.c) $< -o $@

all: $(NAME)

$(NAME): 	$(BANNER) $(LIBFT) $(OBJS)
			@echo "$(YELLOW) Creating minishell... $(WHITE)"
			$(CC) $(CFLAGS) $(OBJS) $(INC_READLINE)\
			 $(READLINE_FLAGS) $(LIBFT) -o $(NAME)
			@echo "\n$(LIGHT_GRAY)---------- MiniShell Ready ------------\n"

$(LIBFT):
			echo "$(LIGHT_RED) Creating libft files... $(WHITE)"
			$(MAKE) bonus -C $(LIBFTDIR)
	
clean:
		@echo "\n"
		@echo "$(LIGHT_RED) Cleaning libft files... $(WHITE)\n"
		@$(MAKE) fclean -C $(LIBFTDIR) 
		/bin/rm -rf $(OBJS)

fclean: clean
		$(RM) $(NAME) $(OBJ_DIR)
		$(RM) src/exec/fullinfile
		@echo "$(GREEN) *** **** DONE **** *** $(WHITE)\n"
				

re: 	fclean all

.PHONY: all clean fclean re

# COLORS
RED				= \033[0;31m
GREEN			= \033[0;32m
YELLOW			= \033[0;33m
BLUE			= \033[0;34m
MAGENTA			= \033[0;35m
CYAN			= \033[0;36m
LIGHT_GRAY		= \033[0;37m
DARK_GRAY		= \033[0;90m
LIGHT_RED		= \033[0;91m
WHITE			= \033[0;97m

#SETS
BOLD			= \e[0;1m
UNDERLINED		= \e[0;4m
BLINK			= \e[0;5m