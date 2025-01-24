# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 15:02:09 by imqandyl          #+#    #+#              #
#    Updated: 2025/01/24 18:36:59 by imqandyl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

CC := gcc
CFLAGS := -Wall -Wextra -Werror -Iinclude
LIBRARY := -L./minilibx -lmlx -framework OpenGL -framework AppKit

SRCS := fractol.c julia.c atof.c keycontrols.c render.c mandelbrot.c
SOURCE := $(addprefix resources/, $(SRCS))
OBJ := $(SOURCE:.c=.o)
MINILIBX := minilibx/

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBRARY) -o $(NAME)

resources/%.o: resources/%.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(MINILIBX)
	rm -f $(OBJ) # Remove object files

fclean: clean
	rm -f $(NAME)

re: fclean all