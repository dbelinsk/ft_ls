# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbelinsk <dbelinsk42@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 13:20:29 by dbelinsk          #+#    #+#              #
#    Updated: 2025/01/16 14:44:54 by dbelinsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_ls

COMP_FLAG=-Wall -Wextra -Werror

SRC_PATH=./src/
OBJ_PATH=./.obj/
LIB_PATH=./lib/
INC_PATH=./include/  $(LIB_PATH)libft/include

SRC_NAME=$(shell find $(SRC_PATH) -name "*.c" | rev | cut -d '/' -f1 | rev)
OBJ_NAME=$(patsubst %.c, %.o, $(SRC_NAME))
LIB_NAME= libft 

SRCS=$(shell find $(SRC_PATH) -name "*.c")
OBJS=$(patsubst %.c, %.o, $(SRCS))
OBJ=$(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC=$(addprefix -I, $(INC_PATH))
LIBS=$(addprefix $(LIB_PATH), $(LIB_NAME))
LIB=$(addprefix -L, $(LIBS))

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\033[99D\033[J\033[0;32mCompiling libraries"
	@make -C $(LIB_PATH)libft/ > /dev/null 2>&1
	@printf "\033[99D\033[J\033[0;32mCompiling objs"
	@gcc $(COMP_FLAG) $(INC) $(LIB) $(OBJ) -lft -o $(NAME)
	@printf "\033[99D\033[J\033[0;32mYou are ready to use $(NAME)!\n\033[m"

soft: $(OBJS)
	@gcc $(INC) $(LIB) $(OBJ) -lft -o $(NAME)> /dev/null 2>&1

%.o: %.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(COMP_FLAG) $(INC) -o $@ -c $<
	@mv $@ $(OBJ_PATH)

clean:
	@printf "\033[99D\033[J\033[0;32mCleaning libraries objects"
	@make -C $(LIB_PATH)libft clean > /dev/null 2>&1
	@printf "\033[99D\033[J\033[0;32mCleaning source objects"
	@rm -fv $(OBJ) > /dev/null 2>&1
	@rm -rf $(OBJ_PATH) > /dev/null 2>&1
	@printf "\033[99D\033[J\033[0;32mCleaning done\n"

fclean: clean
	@printf "\033[99D\033[J\033[0;32mForce cleaning libraries executable"
	@make -C $(LIB_PATH)libft fclean > /dev/null 2>&1
	@printf "\033[99D\033[J\033[0;32mForce cleaning executable"
	@rm -fv $(NAME) > /dev/null 2>&1
	@printf "\033[99D\033[J\033[0;32mForce cleaning done\n"

re: fclean all