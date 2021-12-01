# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/13 11:30:03 by mahadad           #+#    #+#              #
#    Updated: 2021/12/01 13:04:10 by mahadad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# _.-=+=-._.-=+=-._[ Var ]_.-=+=-._.-=+=-._ #

NAME = <exe or lib>

INCLUDES = -I includes/
DEP_LIBFT = 
# _.-=+=-._.-=+=-._[ Source & Bin ]_.-=+=-._.-=+=-._ #

all: $(NAME)
	@printf "\033[32;1m[== $(NAME) Created ! ==]\033[32;0m\n"

$(NAME): 
	@ar -rcs $(NAME) 
	@printf "\033[32;1m[== Linked OK ==]\033[32;0m\n"

clean:
	@rm -rf $(OBJS)
	@printf "\033[31;1m[Remove *.o]\033[32;0m\n"
	@rm -rf $(OBJ_DIR)
	@printf "\033[31;1m[Remove $(OBJ_DIR)]\033[32;0m\n"

fclean: clean
	@rm -f $(NAME)
	@printf "\033[31;1m[Remove $(NAME)]\033[32;0m\n"

re: fclean all

.PHONY: all, clean, fclean, re

# _.-=+=-._.-=+=-._[ Dev Tools ]_.-=+=-._.-=+=-._ #
.PHONY: c, cf, r, git, h

h:
	@echo "\033[1J"

c: clean

fc: fclean

r: re

git:
	@git pull
	@-git add .
	@git commit -am "Makefile push `date +'%Y-%m-%d %H:%M:%S'`"
	@-git push