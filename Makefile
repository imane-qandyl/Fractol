# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/30 18:28:03 by imqandyl          #+#    #+#              #
#    Updated: 2024/09/21 20:11:16 by imqandyl         ###   ########.fr        #
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
	make -C $(MINILIBX) # Build the MiniLibX library
	$(CC) $(CFLAGS) $(OBJ) $(LIBRARY) -o $(NAME)

resources/%.o: resources/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(MINILIBX) # Clean MiniLibX build
	rm -f $(OBJ) # Remove object files

fclean: clean
	rm -f $(NAME) # Remove the final executable

re: fclean all