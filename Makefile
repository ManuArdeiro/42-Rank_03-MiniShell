# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/01 18:51:45 by jolopez-          #+#    #+#              #
#    Updated: 2023/10/09 18:56:01 by yzaytoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	minishell

vpath 			%.h	include
vpath 			%.c	src
vpath 			%.c	src/utils
vpath			%.c src/env
vpath			%.c src/parser
vpath			%.c src/lexer
vpath			%.c src/minitree
vpath			%.c src/summarizer
vpath			%.c src/exec
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
INC_READLINE	= -I/Users/$(USER)/.brew/opt/readline/include
READLINE_LIB	= -L/Users/$(USER)/.brew/opt/readline/lib
#INC_READLINE	="-L/usr/local/opt/readline/lib"
#READLINE_LIB	="-I/usr/local/opt/readline/include"
SANITIZER		= -g3 -fsanitize=address -g

READLINE_FLAGS	= -lreadline

#-------------------------- C Files -------------------------------------
ENV				= ft_getenv.c ft_setenv.c ft_initenv.c ft_printenv.c

UTILS			= print_msg.c mini_history.c get_path.c free_string.c \
					mini_dictionary.c
LEXER			= tokenizer.c tokens.c token_tools_1.c token_tools_2.c \
					ft_copy_tokenlist.c ft_tokenlist_add.c
PARSER			= get_commandlist.c separators.c convertlist.c \
					get_arglist.c extract_tokenstring.c extract_filelist.c \
					get_tokennode.c lstconvert.c printcommand.c \
					generate_parsetree.c grammar.c isvalid_commandtree.c \
					tokensplit.c lookahead.c create_mininode.c

SUMMARIZER		= minisummary.c printtokens.c get_unique_tokens.c \
					get_token_summary.c get_token_count.c

TREE 			= minitree.c treetraversal.c

EXEC			= executor.c openfile.c

SRC 			= $(ENV) $(UTILS) $(PARSER) $(TREE) $(SUMMARIZER) $(EXEC) $(LEXER) main.c

COMMANDS		= 	Pipex
BUILTINS		= 	$(addprefix "src/cmd/", $(COMMANDS))
#------------------------------------------------------------------------

OBJS			=	$(SRC:%.c=$(OBJ_DIR)/%.o)

RM 				=	/bin/rm -rf
CC 				= 	gcc
CFLAGS 			= 	-Wall -Werror -Wextra $(INCLUDE) $(INC_LIB) $(READLINE_INC) $(SANITIZER)

LIBFT			= 	include/libft/libft.a
LIBFTDIR		= 	include/libft
OBJ_DIR			=	obj

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(@D)
	$(COMPILE.c) $< -o $@

all: $(NAME)

$(NAME): 	$(BANNER) $(LIBFT) $(BUILTINS) $(OBJS)
			@echo "$(YELLOW) Creating minishell... $(WHITE)"
			$(CC) $(CFLAGS) $(OBJS) $(READLINE_LIB)\
			 $(READLINE_FLAGS) $(LIBFT) -o $(NAME)
			@echo "\n$(LIGHT_GRAY)---------- MiniShell Ready ------------\n"
.SILENT:
$(LIBFT):
			echo "$(LIGHT_RED) Creating libft files... $(WHITE)"
			$(MAKE) bonus -C $(LIBFTDIR)
	
$(BUILTINS):
			@echo "$(YELLOW) Creating Object files... $(WHITE)"	
			@$(MAKE) -C $@
clean:
		@echo "\n"
		@echo "$(LIGHT_RED) Cleaning libft files... $(WHITE)\n"
		@$(MAKE) fclean -C $(LIBFTDIR) 
		@$(MAKE) fclean -C $(BUILTINS) 
		/bin/rm -rf $(OBJS)

fclean: clean
		$(RM) $(NAME) $(OBJ_DIR)
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