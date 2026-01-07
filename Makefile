# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/22 10:14:02 by skayed            #+#    #+#              #
#    Updated: 2025/10/27 15:58:21 by skayed           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -g -gdwarf-4 -O0 -I./include -Imlx -Wall -Wextra -Werror

MKDIR = mkdir -p

MINILIBX_PATH = libraries/mlx
MINILIBX = $(MINILIBX_PATH)/libmlx.a

LIBFT_PATH = libraries/libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC = main.c \
	check_cub.c \
	parsing_utils.c \
	parse_texture.c \
	parse_rgb.c \
	parse_map.c \
	check_map.c \
	init_render.c \
	draw_3d.c \
	init_mlx.c \
	raycast.c \
	moves.c \
	init_ray.c \
	init_wall.c \
	init_struct.c \
	exit.c
	
vpath %.c parsing \
	:rendering \
	:utils
 
OBJ = $(addprefix objs/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(MINILIBX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBX) \
	-L$(MINILIBX_PATH) -lmlx_Linux \
	-L/usr/lib -lXext -lX11 -lm -lz \
	-o $(NAME)
	
objs/%.o: %.c mkobjsdir
	$(CC) $(CFLAGS) -I/usr/include -Imlx -I$(LIBFT_PATH) -O3 -c $< -o $@

mkobjsdir:
	$(MKDIR) objs

clean: 
	rm -f $(OBJ)
	make -C $(MINILIBX_PATH) clean
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(MINILIBX_PATH) clean
	make -C $(LIBFT_PATH) fclean

re:	fclean all

$(MINILIBX):
	chmod 777 $(MINILIBX_PATH)/configure
	make -C $(MINILIBX_PATH)

$(LIBFT):
	make -C $(LIBFT_PATH)

.PHONY: all bonus clean fclean re
