# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/01 18:51:45 by jolopez-          #+#    #+#              #
#    Updated: 2023/09/08 21:01:18 by yzaytoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	minishell

vpath 			%.h	include
vpath 			%.c	src
vpath 			%.c	src/utils
vpath 			%.c	src/Commands
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

READLINE_FLAGS	= -lreadline
SRC 			= main.c print_msg.c

OBJS			=	$(SRC:%.c=$(OBJ_DIR)/%.o)

CC 				= 	gcc

CFLAGS 			= 	-Wall -Werror -Wextra $(INCLUDE) $(INC_LIB) $(READLINE_INC)#-g3 -fsanitize=address

LIBFT			= 	include/libft/libft.a

BUILTINS		= 	src/Commands/Pipex/pipex

OBJ_DIR			=	obj

RM 				= /bin/rm -rf

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(@D)
	@echo "$(YELLOW) Creating Object files... $(WHITE)"	
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
			cd include/libft && make bonus
	
$(BUILTINS):
			@$(MAKE) -C src/Commands/Pipex
clean:
		@echo "\n"
		@echo "$(LIGHT_RED) Cleaning libft files... $(WHITE)\n"
		cd include/libft && make clean
		@$(MAKE) fclean -C src/Commands/Pipex 
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