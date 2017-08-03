# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryukhyme <ryukhyme@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 09:49:16 by vrudakov          #+#    #+#              #
#    Updated: 2017/01/06 21:13:03 by ryukhyme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = val_of_str.c trim_tetri.c find_tetri.c board.c solver.c        \
	vr_coord.c main.c ft_strnew.c ft_strdup.c                       \
	ft_strjoin.c ft_strcat.c ft_memset.c ft_strcmp.c ft_strcpy.c    \
	ft_strlen.c ft_strncpy.c ft_strsub.c ft_strsplit.c
FLAG = -Wall -Wextra -Werror
OBJ = $(subst .c,.o, $(SRC))

all: compile

compile: 
	gcc $(FLAG) -o $(NAME) $(SRC)

clean:
		rm -f $(OBJ)

fclean:clean
		rm -f $(NAME)

re:	fclean all
