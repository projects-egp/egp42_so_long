# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enrgil-p <enrgil-p@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/02 22:51:58 by enrgil-p          #+#    #+#              #
#    Updated: 2025/07/04 20:54:41 by enrgil-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SOURCES =

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJECTS = $(SRCS:c=.o)

CFLAGS = -Wall -Wextra -Werror -g3
LIBFT_FLAG = -L $(LIBFT_DIR) -l ft
SANIT_FLAG = -fsanitize=address
CC = cc
RM = rm -f

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)
	$(info CREATED $(LIBFT))

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(SOURCES) $(LIBFT_FLAG) -o $(NAME)
	$(info CREATED $(NAME))

fsanitize: $(NAME)
	$(CC) $(CFLAGS) $(SANIT_FLAG) $(SOURCES) $(LIBFT_FLAG) -o $(NAME)
	$(info CREATED $(NAME) with fsanitize)

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean
	$(info REMOVED OBJECTS AND LIBFT/OBJECTS)

compclean: all clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	$(info REMOVED $(NAME) AND -IN CASE THESE EXISTED YET- OBJECTS)

re: fclean all

.PHONY: all clean fclean re fsantize compclean
