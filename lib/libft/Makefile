# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 13:20:58 by dbelinsk          #+#    #+#              #
#    Updated: 2025/01/22 15:15:18 by dbelinsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= libft.a

CC			= gcc
FLAGS		= -c -Wall -Wextra -Werror

SRC_PATH=./src
OBJ_PATH=./.obj/
INC_PATH=./include/

SRC_NAME=$(shell find $(SRC_PATH) -name "*.c" | rev | cut -d '/' -f1 | rev)
OBJ_NAME=$(patsubst %.c, %.o, $(SRC_NAME))


SRCS=$(shell find $(SRC_PATH) -name "*.c")
OBJS=$(SRCS:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)
INC=$(addprefix -I, $(INC_PATH))
LIBS=$(addprefix $(LIB_PATH), $(LIB_NAME))
LIB=$(addprefix -L, $(LIBS))

all: $(NAME)
	@printf "\033[0;32mlibft ready!\n"


	
$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "\033[99D\033[J\033[0;33m"

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
	@printf "\033[99D\033[J\033[0;33mCompiling libft ---> $*"
	@mkdir -p $(OBJ_PATH)
	@gcc $(COMP_FLAG) $(INC) -c $< -o $@ 

clean:
	@rm -fv $(OBJ)  > /dev/null 2>&1
	@rm -rf $(OBJ_PATH)  > /dev/null 2>&1

fclean: clean
	@rm -fv $(NAME)  > /dev/null 2>&1

re: fclean all
