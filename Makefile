# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/01 18:51:45 by jolopez-          #+#    #+#              #
#    Updated: 2023/11/09 18:00:40 by yzaytoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 			=	minishell

vpath 			%.h	include
vpath 			%.c	src : src/cmd/built_ins : src/cmd : src/env : src/exec \
				: src/lexer : src/minitree : src/summarizer : src/utils
vpath			%.c src/parser : src/parser/command : src/parser/file
vpath 			%.o	obj

WHITE_BAN        := $(shell tput -Txterm setaf 7)                                     

BANNER = 	$(info $(WHITE_BAN))\
			$(info  @@@@@@@@@@   @@@  @@@  @@@  @@@      @@@@@@   @@@  @@@  @@@@@@@@  @@@       @@@		  )\
			$(info	@@@@@@@@@@@  @@@  @@@@ @@@  @@@     @@@@@@@   @@@  @@@  @@@@@@@@  @@@       @@@       )\
			$(info	@@! @@! @@!  @@!  @@!@!@@@  @@!     !@@       @@!  @@@  @@!       @@!       @@!       )\
			$(info	!@! !@! !@!  !@!  !@!!@!@!  !@!     !@!       !@!  @!@  !@!       !@!       !@!       )\
			$(info	@!! !!@ @!@  !!@  @!@ !!@!  !!@     !!@@!!    @!@!@!@!  @!!!:!    @!!       @!!       )\
			$(info	!@!   ! !@!  !!!  !@!  !!!  !!!      !!@!!!   !!!@!!!!  !!!!!:    !!!       !!!       )\
			$(info	!!:     !!:  !!:  !!:  !!!  !!:          !:!  !!:  !!!  !!:       !!:       !!:       )\
			$(info	:!:     :!:  :!:  :!:  !:!  :!:         !:!   :!:  !:!  :!:        :!:       :!:      )\
			$(info	:::     ::    ::   ::   ::   ::     :::: ::   ::   :::   :: ::::   :: ::::   :: ::::  )\
			$(info	 :      :    :    ::    :   :       :: : :     :   : :  : :: ::   : :: : :  : :: : :  )\
			$(info	                                                                                      )\
			$(info **************************************************************************************)

USER			= $(shell whoami)
INCLUDE 		= -Iinclude/
INC_LIB 		= -Iinclude/libft
#READLINE_LIB	= -I/Users/$(USER)/.brew/opt/readline/include
#INC_READLINE	= -L/Users/$(USER)/.brew/opt/readline/lib
INC_READLINE	= -L/usr/local/opt/readline/lib
READLINE_LIB	= -I/usr/local/opt/readline/include
SANITIZER		= -g3 -fsanitize=address -g

READLINE_FLAGS	= -lreadline

#-------------------------- C Files -------------------------------------
ENV				= ft_getenv.c ft_setenv.c ft_initenv.c ft_delenv.c

UTILS			= print_msg.c mini_history.c get_path.c free_string.c \
					mini_dictionary.c signals.c

LEXER			= tokenizer.c tokens.c token_tools_1.c token_tools_2.c \
					ft_copy_tokenlist.c ft_tokenlist_add.c print_tokens.c \
					add_tkn.c free_tokenlist.c

COMMAND			= extract_tokenstring.c get_commandlist.c lstconvert.c \
					printcommand.c extract_filelist.c get_minicommand.c \
					extract_arglist.c is_compoundcommand.c free_commandlist.c
					
FILE			= create_file.c get_filemode.c add_pipeline.c is_redirection.c \
					freefile.c append_filecontent.c delete_filenode.c

PARSER			=  separators.c get_tokennode.c tokensplit.c get_nodetype.c \
					parse_commandline.c contains_tokenseparator.c \
					$(COMMAND) $(FILE)
					
SUMMARIZER		= minisummary.c printtokens.c get_unique_tokens.c \
					get_token_summary.c get_token_count.c

CMD				= mini_cd.c mini_echo.c mini_env.c mini_exit.c mini_export.c mini_pwd.c \
					mini_unset.c mini_builtins.c is_builtin.c
					
TREE 			= minitree.c treetraversal.c is_emptynode.c create_mininode.c \
				print_tree.c get_lasttreenode.c free_mininode.c
					
EXEC			= executecommand.c openfile.c execute_commandline.c \
				goto_childnode.c add_pathprefix.c evaluate_subprocess.c \
				wait_subprocess.c create_subprocess.c execute_subprocess.c \
				expand_startoken.c expand_dollartoken.c execute_builtin.c \
				mini_heredoc.c expand_filelist.c

SRC 			= $(ENV) $(UTILS) $(SUMMARIZER) $(LEXER) \
					$(CMD) $(PARSER) $(TREE) $(EXEC)  main.c

OBJS			=	$(SRC:%.c=$(OBJ_DIR)/%.o)

RM 				=	/bin/rm -rf
CC 				= 	gcc
CFLAGS 			= 	-Wall -Werror -Wextra $(INCLUDE) $(INC_LIB) $(READLINE_LIB) $(SANITIZER)

LIBFT			= 	include/libft/libft.a
LIBFTDIR		= 	include/libft
OBJ_DIR			=	obj

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(@D)
	$(COMPILE.c) $< -o $@

all: $(NAME)

$(NAME): 	$(BANNER) $(LIBFT) $(OBJS)
			@echo "$(YELLOW) Creating minishell... $(WHITE)"
			$(CC) $(CFLAGS) $(OBJS) $(INC_READLINE)\
			 $(READLINE_FLAGS) $(LIBFT) -o $(NAME)
			@echo "\n$(LIGHT_GRAY)---------- MiniShell Ready ------------\n"
.SILENT:
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