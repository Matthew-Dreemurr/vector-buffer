# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/13 11:30:03 by mahadad           #+#    #+#              #
#    Updated: 2021/12/01 16:24:11 by mahadad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# _.-=+=-._.-=+=-._[ Var ]_.-=+=-._.-=+=-._ #

NAME = vector_buffer.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
INCLUDES = -I includes/ -I ../libft/includes/

COMP_D = 0
D = 0
SANI = 0

ifeq ($(SANI), 1)
CFLAGS += -fsanitize=address
D = 1
endif

ifeq ($(D), 1)
CFLAGS += -g3
endif

# _.-=+=-._.-=+=-._[ Source & Bin ]_.-=+=-._.-=+=-._ #
.PHONY: all, clean, fclean, re

SRC_DIR = src/
OBJ_DIR = obj_$(basename $(NAME))/

HEADER = ../includes/vector.h

DEP_LIBFT = ../libft/obj_libft

SRCS = $(shell find src -type f -name "*.c")

SRC		= $(notdir $(SRCS))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_DIR), $(OBJ))

VPATH	= $(SRC_DIR) $(OBJ_DIR) $(shell find $(SRC_DIR) -type d)

all: $(NAME)

$(DEP_LIBFT):
	@make only_obj -C ../libft

$(OBJ_DIR)%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@if [[ $(COMP_D) = "0" ]]; then printf "\033[32;1m.\033[32;0m"; else printf "\033[32;1m$@\033[32;0m\n"; fi

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@printf "\033[32;1m[Create $(OBJ_DIR)]\033[32;0m\n"

$(NAME): $(OBJ_DIR) $(OBJS) $(DEP_LIBFT)
	@ar -rcs $(NAME) $(OBJS) $(shell find $(DEP_LIBFT) -type f -name "*.o")
	@printf "\n\033[32;1m[== $(NAME) Created ! ==]\033[32;0m\n"
	@if [[ $D = "1" ]]; then printf "\033[31;1m[/!\\ DEBUG ENABLE /!\\]\033[32;0m\n"; fi
	@printf "\n[Compiled /w this flag $(CFLAGS)]\n"

clean:
	@make clean -C ../libft
	@rm -rf $(OBJS)
	@printf "\033[31;1m[Remove *.o]\033[32;0m\n"
	@rm -rf $(OBJ_DIR)
	@printf "\033[31;1m[Remove $(OBJ_DIR)]\033[32;0m\n"

fclean: clean
	make fclean -C ../libft
	@rm -f $(NAME)
	@printf "\033[31;1m[Remove $(NAME)]\033[32;0m\n"

re: fclean all
# _.-=+=-._.-=+=-._[ Dev Tools ]_.-=+=-._.-=+=-._ #
.PHONY: c, cf, r, git, h, test

test: $(NAME)
	$(CC) $(CFLAGS) $(NAME) test/test_main.c -o vect_test

h:
	@echo "\033[1J"

c: clean

fc: fclean

r: re

git:
	@git pull
	@git status --short
	@while true; do read -p "Continue [y/N]" resp; if [[ $$resp =~ ^[Yy]$$ ]]; then exit 0; else exit 1; fi; done
	@-git add .
	@git commit -am "Makefile push `date +'%Y-%m-%d %H:%M:%S'`"
	@-git push