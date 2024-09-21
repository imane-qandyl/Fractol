# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/30 18:28:03 by imqandyl          #+#    #+#              #
#    Updated: 2024/09/20 18:02:42 by imqandyl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

CC := gcc
CFLAGS := -Wall -Wextra -Werror -Iinclude 
LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit

# LIBFT_PATH := libft
# LIBFT := $(LIBFT_PATH)/libft.a

SOURCE := resources/*.c
MINILIBX := minilibx/

all: $(NAME)

$(NAME):
	make -C $(MINILIBX) # Build the MiniLibX library
	$(CC) $(CFLAGS) $(SOURCE) $(LIBRARY) -o $(NAME)

clean:
	make clean -C $(MINILIBX)

fclean: clean
	rm -f $(NAME)

re: fclean all
