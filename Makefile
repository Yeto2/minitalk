# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 21:56:01 by yessemna          #+#    #+#              #
#    Updated: 2024/03/23 22:25:55 by yessemna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME_S = server
NAME_C = client
NAME_SBONUS = server_bonus
NAME_CBONUS = client_bonus

SRC_S = Mandatory/server.c \
						utils/ft_putstr_fd.c \
						utils/ft_putchar_fd.c \
						utils/ft_putnbr_fd.c \
						utils/ft_putendl_fd.c \
						utils/ft_isdigit.c \
						utils/ft_putchar.c \
						utils/tools.c
						
SRC_C = Mandatory/client.c \
						utils/ft_putstr_fd.c \
						utils/ft_putchar_fd.c \
						utils/ft_putnbr_fd.c \
						utils/ft_putendl_fd.c \
						utils/ft_isdigit.c \
						utils/ft_putchar.c \
						utils/tools.c
						
SRC_SB = Bonus/server_bonus.c \
						utils/ft_putstr_fd.c \
						utils/ft_putchar_fd.c \
						utils/ft_putnbr_fd.c \
						utils/ft_putendl_fd.c \
						utils/ft_isdigit.c \
						utils/ft_putchar.c \
						utils/tools.c
SRC_CB = Bonus/client_bonus.c \
						utils/ft_putstr_fd.c \
						utils/ft_putchar_fd.c \
						utils/ft_putnbr_fd.c \
						utils/ft_putendl_fd.c \
						utils/ft_isdigit.c \
						utils/ft_putchar.c \
						utils/tools.c

COMM_OBJ = $(COMM_SRC:.c=.o)
OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)
OBJ_SB = $(SRC_SB:.c=.o)
OBJ_CB = $(SRC_CB:.c=.o)

Mandatory/%.o: Mandatory/%.c minitalk.h
	@ $(CC) $(FLAGS) -o $@ -c $<
	
Bonus/%.o: Bonus/%.c minitalk.h
	@ $(CC) $(FLAGS) -o $@ -c $<
	
all: client server
bonus: client_bonus server_bonus

server: $(OBJ_S)
	@ $(CC) $(OBJ_S) -o $(NAME_S)

client: $(OBJ_C)
	@ $(CC)  $(OBJ_C) -o $(NAME_C)

server_bonus: $(OBJ_SB)
	@ $(CC) $(FLAGS) $(OBJ_SB) -o $(NAME_SBONUS)

client_bonus: $(OBJ_CB)
	@ $(CC) $(FLAGS) $(OBJ_CB) -o $(NAME_CBONUS)

clean:
	@ $(RM) $(OBJ_S) $(OBJ_C)
	@ $(RM) $(OBJ_SB) $(OBJ_CB)

fclean: clean
	@ $(RM) $(NAME_S) $(NAME_C)
	@ $(RM) $(NAME_SBONUS) $(NAME_CBONUS)

re: clean all

.PHONY: clean all fclean re bonus 