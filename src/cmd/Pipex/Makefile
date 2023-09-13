# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 19:16:59 by yzaytoun          #+#    #+#              #
#    Updated: 2022/11/02 21:07:52by yzaytoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIB_PATH = ../../../

vpath %.c src
vpath %.h include
vpath %.h $(LIB_DIR)include
vpath %.h $(LIB_PATH)include/libft
vpath %.o obj


# ************************ Colors ***********************************
ifneq (,$(findstring xterm,${TERM}))
	BLACK        := $(shell tput -Txterm setaf 0)
	RED          := $(shell tput -Txterm setaf 1)
	GREEN        := $(shell tput -Txterm setaf 2)
	YELLOW       := $(shell tput -Txterm setaf 3)
	LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
	PURPLE       := $(shell tput -Txterm setaf 5)
	BLUE         := $(shell tput -Txterm setaf 6)
	WHITE        := $(shell tput -Txterm setaf 7)
	RESET := $(shell tput -Txterm sgr0)
else
	BLACK        := ""
	RED          := ""
	GREEN        := ""
	YELLOW       := ""
	LIGHTPURPLE  := ""
	PURPLE       := ""
	BLUE         := ""
	WHITE        := ""
	RESET        := ""
endif

# --------------------- Definitions ------------------------------------
CC = gcc 
INC = -I include
LIB = -I $(LIB_PATH)include/libft
MINILIB = -I $(LIB_PATH)include
CFLAGS = -Wall -Wextra -Werror $(INC) $(LIB) $(MINILIB)
RM = rm -fr

# ------------------ Libft and printf ------------------------------
LIBFT = $(LIB_PATH)include/libft/libft.a
LINKFOLDER = -L $(LIB_PATH)/include/libft
# ------------------------ Pipex ------------------------------
SRC = main.c pipe_com.c pipex_IO.c pipex_aux.c\
		pipex_free.c pipex_list.c pipex_util.c pipex_string.c\
		heredoc_bonus.c pipes_aux_bonus.c pipex_free_bonus.c

OBJDIR = obj

PIP_OBJ := $(SRC:%.c=$(OBJDIR)/%.o)
PIP_OBJB := $(BONUS:%.c=$(OBJDIR)/%.o)

.SILENT:
$(OBJDIR)/%.o:%.c
	@mkdir -p $(@D)
	$(COMPILE.c) -o $@ $<


all: $(NAME)

$(NAME): $(PIP_OBJ) $(OBJDIR)
	@$(CC) $(CFLAGS) $(PIP_OBJ) $(LIBFT) $(LINKFOLDER) -o $@
	@chmod +x pipex

fclean: clean
	@$(RM) $(NAME) pipex

clean:
	$(RM) $(PIP_OBJ) $(PIP_OBJB)
	$(RM) $(OBJDIR)

re: fclean all

.PHONY: re all fclean clean