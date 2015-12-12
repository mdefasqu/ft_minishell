# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 12:58:41 by mdefasqu          #+#    #+#              #
#    Updated: 2015/09/11 12:14:20 by mdefasqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDE = libft.h

SRC = $(shell ls -1 | grep "\.c")

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
		@gcc -Wall -Werror -Wextra -c $(SRC)
		@ar rc $(NAME) $(OBJ)

clean:
		@/bin/rm -f $(OBJ)

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all
