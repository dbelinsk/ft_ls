# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 13:20:29 by dbelinsk          #+#    #+#              #
#    Updated: 2025/01/22 15:15:15 by dbelinsk         ###   ########.fr        #
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
OBJS=$(SRCS:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)
INC=$(addprefix -I, $(INC_PATH))
LIBS=$(addprefix $(LIB_PATH), $(LIB_NAME))
LIB=$(addprefix -L, $(LIBS))

all: libft $(NAME) 
	@printf "\033[99D\033[J\033[0;32mft_ls ready!\n"
	@printf "You are ready to use $(NAME)!\n\033[m"
	

libft: 
	@make -C $(LIB_PATH)libft/ 

$(NAME): $(OBJS)
	@gcc $(COMP_FLAG) $(OBJS) $(INC) $(LIB) -lft -o $(NAME)

soft: $(OBJS)
	@gcc $(INC) $(LIB) $(OBJ) -lft -o $(NAME)# > /dev/null 2>&1

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
	@printf "\033[99D\033[J\033[0;33mCompiling ft_ls ---> $*"
	@mkdir -p $(OBJ_PATH)
	@gcc $(COMP_FLAG) $(INC) -o $@ -c $<
	
clean:
	@make -C $(LIB_PATH)libft clean  > /dev/null 2>&1
	@rm -fv $(OBJ)  > /dev/null 2>&1
	@rm -rf $(OBJ_PATH) # > /dev/null 2>&1

fclean: clean
	@make -C $(LIB_PATH)libft fclean  > /dev/null 2>&1
	@rm -fv $(NAME)  > /dev/null 2>&1

re: fclean all