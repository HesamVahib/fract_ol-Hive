# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 11:34:02 by mspasic           #+#    #+#              #
#    Updated: 2025/02/24 22:28:18 by hvahib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Werror -Wextra

MLX_PATH = MLX42/
MLX_NAME = build/libmlx42.a
MLX = $(MLX_PATH)$(MLX_NAME)

LIBFT_PATH = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

HEADERS = -I $(MLX_PATH)include -I $(LIBFT_PATH)

SOURCE_FILES = 	main.c \
				fractol_utils.c \
				image_filling.c \
				Julia.c \
				Mandelbrot.c \
				painting.c

OBJECT_FILES = $(SOURCE_FILES:.c=.o)
LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lglfw
# the linker flags


all: $(NAME)

$(NAME): $(LIBFT) $(OBJECT_FILES)
	cmake $(MLX_PATH) -B $(MLX_PATH)build && make -C $(MLX_PATH)build -j4
	$(CC) $(CFLAGS) $(OBJECT_FILES) $(LIBFT) $(HEADERS) $(MLX) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)


%.o: %.c 
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	rm -f $(OBJECT_FILES)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	rm -rf MLX42/build
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: clean fclean all re libft libmlx
