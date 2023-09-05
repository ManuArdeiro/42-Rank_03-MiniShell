# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/01 18:51:45 by jolopez-          #+#    #+#              #
#    Updated: 2023/09/05 20:02:58 by yzaytoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	minishell

vpath 			%.h	include
vpath 			%.c	src
vpath 			%.o	obj

WHITE_BAN        := $(shell tput -Txterm setaf 7)                                     

BANNER = 	$(info $(WHITE_BAN))\
			$(info @@@@@@@@@@   @@@  @@@  @@@  @@@      @@@@@@   @@@  @@@  @@@@@@@@  @@@       @@@		  )\
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

INCLUDE 		=	include/
INC_LIB 		=	include/libft

SRC 			= 	main.c

OBJS			=	$(SRC:%.c=$(OBJ_DIR)/%.o)

CC 				= 	gcc

CFLAGS 			= 	-Wall -Werror -Wextra -I$(INCLUDE) -I$(INC_LIB)#-g3 -fsanitize=address

LIBFT			= 	include/libft/libft.a

OBJ_DIR			=	obj

RM 				= /bin/rm -rf 

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(@D)
	@echo "$(YELLOW) Creating Object files... $(WHITE)"	
	$(COMPILE.c) $< -o $@

all: $(NAME)

$(NAME): 		$(BANNER) $(LIBFT) $(OBJS)
				@echo "$(YELLOW) Creating minishell... $(WHITE)"
				$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)	
.SILENT:
$(LIBFT):
				echo "$(LIGHT_RED) Creating libft files... $(WHITE)"
				cd include/libft && make bonus
	
clean:
				@echo "\n"
				@echo "$(LIGHT_RED) Cleaning libft files... $(WHITE)\n"
				cd include/libft && make clean 
				/bin/rm -rf $(OBJS)

fclean: 		clean
				$(RM) $(NAME) $(OBJ_DIR)
				@echo "$(GREEN) *** **** DONE **** *** $(WHITE)\n"
				

re: 			fclean all

.PHONY: 		all clean fclean re  

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