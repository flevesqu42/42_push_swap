# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flevesqu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/22 00:33:10 by flevesqu          #+#    #+#              #
#    Updated: 2016/03/08 03:46:39 by flevesqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCLUDES = libft/includes/

SRC = main.c\
	  second.c\
	  aff.c\
	  aff_2.c\
	  aff_3.c\
	  push_swap.c\
	  algo.c\
	  algo_depend_1.c\
	  algo_depend_2.c\
	  algo_depend_3.c\
	  algo_depend_4.c\
	  algo_4.c

WFLAGS = -Wall -Wextra -Werror

LFLAGS = -L libft/ -lft

CC = gcc

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o: %.c $(NAME).h
	$(CC) -c $(WFLAGS) -I $(INCLUDES) $< -o $@

$(NAME) : $(OBJ) $(NAME).h
	make -C libft
	$(CC) -o $(NAME) $(OBJ) $(WFLAGS) $(LFLAGS)

clean :
	rm -rf $(OBJ)

lclean :
	make -C libft/ clean

fclean : clean
	rm -f $(NAME)

lfclean :
	make -C libft/ fclean

re : fclean all

lre :
	make -C libft/ re

.PHONY: all clean fclean re lclean lfclean lre
