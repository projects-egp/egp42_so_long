# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enrgil-p <enrgil-p@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/02 22:51:58 by enrgil-p          #+#    #+#              #
#    Updated: 2025/07/09 19:12:57 by enrgil-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SOURCES =	main.c map_format.c open_map.c check_line_by_line.c\
		parse_utils.c manage_error.c

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./mlx_linux
MLX = $(MLX_DIR)/libmlx.a

OBJECTS = $(SRCS:c=.o)

CFLAGS = -Wall -Wextra -Werror -g3
SANIT_FLAG = -fsanitize=address

LIBFT_FLAGS = -L $(LIBFT_DIR) -l ft
MLX_FLAGS = -Lmlx_linux -lmlx_Linux  -L/usr/lib/X11 -lXext -lX11
LIBS_FLAGS = $(LIBFT_FLAGS) $(MLX_FLAGS)

CC = cc
RM = rm -f

all: $(NAME)

$(LIBFT):
	$(info Compiling Libft...)
	@make -s -C $(LIBFT_DIR)

$(MLX):
	$(info CREATED $(MLX))
	@make -s -C $(MLX_DIR)

$(NAME): $(LIBFT) $(MLX) $(OBJECTS)
	$(CC) $(CFLAGS) $(SOURCES) $(LIBS_FLAGS) -o $(NAME)
	$(info CREATED $(NAME))

fsanitize: $(NAME)
	$(CC) $(CFLAGS) $(SANIT_FLAG) $(SOURCES) $(LIBS_FLAGS) -o $(NAME)
	$(info CREATED $(NAME) with fsanitize)

clean:
	$(RM) $(OBJS)
	@make -s -C $(LIBFT_DIR) clean
	$(info REMOVED OBJECTS AND LIBFT/OBJECTS)

compclean: all clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MLX_DIR) clean
	$(info REMOVED $(NAME), $(MLX) AND -IN CASE THESE EXISTED YET- OBJECTS)

re: fclean all

.PHONY: all clean fclean re fsantize compclean
