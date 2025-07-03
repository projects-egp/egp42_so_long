# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enrgil-p <enrgil-p@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/02 22:51:58 by enrgil-p          #+#    #+#              #
#    Updated: 2025/04/27 15:11:43 by enrgil-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =

OBJS = $(SRCS:c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(NAME) $(OBJS)
#   ar: creates *.a;  r: replace if previous exist; c: creates if doesn't exist

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
