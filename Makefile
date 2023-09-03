# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/01 18:51:45 by jolopez-          #+#    #+#              #
#    Updated: 2023/09/03 20:44:30 by jolopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	minishell

SRCS 			= 	srcs/main.c

OBJS			=	$(SRCS:%.c=%.o)

INC 			=	-I./includes/so_long.h 

LIBS			=	

CC 				= 	gcc

FLAGS 			= 	-Wall -Werror -Wextra $(INC) -g3 -fsanitize=address

all: $(NAME)

$(NAME): 		$(OBJS)
				@echo "$(LIGHT_RED) Creating libft files... $(WHITE)"
				cd ./includes/libft && make bonus && make clean 
				@echo "$(YELLOW) Creating minishell... $(WHITE)"
				$(CC) $(FLAGS) $(OBJS) $(LIBS) -o $(NAME)	

clean:		
				/bin/rm -rf $(OBJS)

fclean: 		clean
				@echo "$(LIGHT_RED) Cleaning all... $(WHITE)"
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