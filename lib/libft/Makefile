# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbelinsk <dbelinsk@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 13:20:58 by dbelinsk          #+#    #+#              #
#    Updated: 2024/12/11 19:33:35 by dbelinsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= 	libft.a

CC			= 	gcc
FLAGS		= 	-c -Wall -Wextra -Werror

SRC_PATH=./src/
OBJ_PATH=./.obj/
INC_PATH=./include/

SRC_NAME=$(shell find $(SRC_PATH) -name "*.c" | rev | cut -d '/' -f1 | rev)
OBJ_NAME=$(patsubst %.c, %.o, $(SRC_NAME))

SRCS=$(shell find $(SRC_PATH) -name "*.c")
OBJS=$(patsubst %.c, %.o, $(SRCS))
OBJ=$(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC=$(addprefix -I, $(INC_PATH))
LIBS=$(addprefix $(LIB_PATH), $(LIB_NAME))
LIB=$(addprefix -L, $(LIBS))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(COMP_FLAG) $(INC) -o $@ -c $<
	@mv $@ $(OBJ_PATH)

clean:
	@rm -fv $(OBJ) > /dev/null 2>&1
	@rm -rf $(OBJ_PATH) > /dev/null 2>&1

fclean: clean
	@rm -fv $(NAME) > /dev/null 2>&1

re: fclean all
