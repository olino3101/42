# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: onault <onault@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 13:56:39 by onault            #+#    #+#              #
#    Updated: 2024/03/12 15:36:26 by onault           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -g -O0

INCDIR = -I includes -I MLX42/includes
SRCS = julia.c mandelbrot.c ft_libft.c check_param.c fractal.c
OBJS = $(SRCS:.c=.o)
GLFW_DIR = $(shell brew --prefix glfw)/lib
GLFW = -lglfw
FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit
L_FLAGS = -L$(GLFW_DIR) $(GLFW) $(FRAMEWORKS)
MLX = MLX42
MLX_LIB = $(MLX)/build/libmlx42.a

.PHONY: all clean fclean re

all: $(NAME)

$(MLX)/build: $(MLX)
	@cmake MLX42 -B MLX42/build && make -C MLX42/build -j4

$(MLX):
	@git clone https://github.com/Golubian/MLX42_4b3deda.git MLX42

$(NAME): $(MLX_LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(L_FLAGS) $(OBJS) $(MLX_LIB) $(INCDIR) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

clean:
	@rm -f $(OBJS)
fclean: clean
	@rm -f $(NAME)
re: fclean all
