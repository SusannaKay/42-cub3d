# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/22 10:14:02 by skayed            #+#    #+#              #
#    Updated: 2025/09/22 11:12:29 by skayed           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -gdwarf-4 -O0 -I./include -Imlx

MINILIBX_PATH = libraries/mlx
MINILIBX = $(MINILIBX_PATH)/libmlx.a

LIBFT_PATH = libraries/libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC = main.c
OBJ = $(SRC: .c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MINILIBX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBX) \
	-L$(MINILIBX_PATH) -lmlx_Linux \
	-L/usr/lib -lXext -lX11 -lm -lz \
	-o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx -I$(LIBFT_PATH) -O3 -c $< -o $@

clean: 
	rm -f $(OBJ)
	make -C $(MINILIBX_PATH) clean
	make -C $(LIBFT_PATH) clean

fclean:
	rm -f $(NAME)
	make -C $(MINILIBX_PATH) fclean
	make -C $(LIBFT_PATH) fclean

re:
	fclean all

$(MINILIBX):
	chmod 777 $(MINILIBX_PATH)/configure
	make -C $(MINILIBX_PATH)

$(LIBFT):
	make -C $(LIBFT_PATH)

.PHONY: all bonus clean fclean re