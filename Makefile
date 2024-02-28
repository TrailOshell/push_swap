# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 23:06:09 by tsomchan          #+#    #+#              #
#    Updated: 2024/02/27 23:27:52by tsomchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
INC_PTH	=	inc/
INC		=	$(addprefix $(INC_PTH), push_swap.h)

SRC_PTH	=	src/
#SRC		=	$(addprefix $(SRC_PTH), push_swap.c)
SRC		=	push_swap.c stack.c node.c do_swap.c do_rotate.c do_reverse.c

OBJ_PTH	=	obj/
#OBJ		=	$(SRC:%.c=$(OBJ_PTH)%.o)
OBJ		=	$(SRC:%.c=$(OBJ_PTH)%.o)

AR		=	ar rc
CC		=	cc
#CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
RM_RF	= 	rm -rf

NC			=	\033[0;0m
BLACK		=	\033[0;30m
D_RED		=	\033[0;31m
D_GREEN		=	\033[0;32m
D_YELLOW	=	\033[0;33m
D_BLUE		=	\033[0;34m
D_PURPLE	=	\033[0;35m
D_CYAN		=	\033[0;36m
L_GRAY		=	\033[0;37m
D_GRAY		=	\033[1;30m
L_RED		=	\033[1;31m
L_GREEN		=	\033[1;32m
L_YELLOW	=	\033[1;33m
L_BLUE		=	\033[1;34m
L_PURPLE	=	\033[1;35m
L_CYAN		=	\033[1;36m
WHITE		=	\033[1;37m

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(D_GREEN)$(NAME) compiled$(NC)"

$(OBJ_PTH)%.o: $(SRC_PTH)%.c $(INC)| $(OBJ_PTH)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
	@echo "$(D_YELLOW)compiled $<$(NC)"

$(OBJ_PTH):
	mkdir -p $(OBJ_PTH)
	@echo "$(D_YELLOW)compiled $@$(NC)"

clean:
	$(RM) $(OBJ)
	$(RM_RF) $(OBJ_PTH)
	@echo "$(D_GRAY)removed object files$(NC)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(D_GRAY)removed $(NAME)$(NC)"

re: fclean all

.PHONY: clean fclean re all

#	my additional rules

clear:
	@clear

norm: clear
	@norminette $(addprefix $(SRC_PTH), $(SRC))

TRASH = .DS_Store

clean_more:
	$(RM_RF) $(TRASH)

#	git

log: clear
	@git log --name-status -3

push:
	@git push
	@git push intra
	@clear && git log --name-status -1

git_add:
	@git add .
ifdef m
	@git commit -m "$(m)"
endif

git: clean_more git_add push

.PHONY += clear norm clean_more log push git_add git

# testing

t: test

test: all
	clear
	./$(NAME) 5 3 2 42 0 -1

.PHONY += t test