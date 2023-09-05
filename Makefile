# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/01 18:51:45 by jolopez-          #+#    #+#              #
#    Updated: 2023/09/05 18:18:42 by jolopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	minishell

vpath 			%.h	include
vpath 			%.c	src lexer
vpath 			%.o	obj

INCLUDE 		=	includes/minishell.h

SRC 			= 	main.c

OBJS			=	$(SRC:%.c=$(OBJ_DIR)/%.o)

CC 				= 	gcc

FLAGS 			= 	-Wall -Werror -Wextra -I$(INCLUDE)#-g3 -fsanitize=address

LIBFT			= 	include/libft/libft.a

OBJ_DIR			=	obj

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(@D)
	$(COMPILE.c) $< -o $@

all: $(NAME)

$(NAME): 		$(LIBFT) $(OBJS)
				@echo "$(YELLOW) Creating minishell... $(WHITE)"
				$(CC) $(OBJS) $(LIBFT) -o $(NAME)	

$(LIBFT):
				@echo "$(LIGHT_RED) Creating libft files... $(WHITE)"
				cd include/libft && make bonus
	
clean:		
				@echo "$(LIGHT_RED) Creating libft files... $(WHITE)"
				cd include/libft && make clean 
				/bin/rm -rf $(OBJS)

fclean: 		clean
				@echo "$(LIGHT_RED) Creating libft files... $(WHITE)"
				cd include/libft && make fclean 
				/bin/rm -rf $(NAME)

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