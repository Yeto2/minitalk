# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 21:56:01 by yessemna          #+#    #+#              #
#    Updated: 2024/02/11 05:27:12 by yessemna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME_S = server
NAME_C = client
NAME_SBONUS = server_bonus
NAME_CBONUS = client_bonus

# COMM_SRC = ft_printf.c ft_printf_utils.c ft_atoi.c
SRC_S = server.c 
SRC_C = client.c 
SRC_SB = server_bonus.c 
SRC_CB = client_bonus.c 

COMM_OBJ = $(COMM_SRC:.c=.o)
OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)
OBJ_SB = $(SRC_SB:.c=.o)
OBJ_CB = $(SRC_CB:.c=.o)

%.o: %.c minitalk.h
	@ $(CC) $(FLAGS) -o $@ -c $<
	
all: client server

server: $(OBJ_S)
	@ $(CC) $(FLAGS) $(OBJ_S) -o $(NAME_S)

client: $(OBJ_C)
	@ $(CC) $(FLAGS) $(OBJ_C) -o $(NAME_C)

clean:
	@ $(RM) $(OBJ_S) $(OBJ_C) $(COMM_OBJ)

fclean: clean
	@ $(RM) $(NAME_S) $(NAME_C)

re: clean all

.PHONY: clean all fclean re bonus 