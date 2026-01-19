/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:13:40 by ebonacco          #+#    #+#             */
/*   Updated: 2026/01/19 10:39:53 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_frame(t_game *game, t_img *frame)
{
	frame->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!frame->img)
		error_exit("mlx_new_image failed\n", game);
	frame->addr = mlx_get_data_addr(frame->img,
									&frame->bit_pp,
									&frame->line_len,
									&frame->endian);
	if (!frame->addr)
		error_exit("mlx_get_data_addr failed\n", game);
}

void	load_hand(t_game *game, t_img *hand, char *path)
{
	hand->img = mlx_xpm_file_to_image(game->mlx, path, &hand->w, &hand->h);
	if (!hand->img)
		error_exit("mlx_xpm_file_to_image failed\n", game);
	hand->addr = mlx_get_data_addr(hand->img, &hand->bit_pp, &hand->line_len,
			&hand->endian);
	if (!hand->addr)
		error_exit("mlx_get_data_addr failed\n", game);
}

void	load_textures(t_game *game, t_img *texture)
{
	int	i;

	i = 0;
	while (i < TEX_COUNT)
	{
		texture[i].img = mlx_xpm_file_to_image(game->mlx,
												game->graphics->paths[i],
												&texture[i].w,
												&texture[i].h);
		if (!texture[i].img)
			error_exit("Failed to load texture\n", game);
		texture[i].addr = mlx_get_data_addr(texture[i].img, &texture[i].bit_pp,
				&texture[i].line_len, &texture[i].endian);
		if (!texture[i].addr)
			error_exit("Failed to get texture data\n", game);
		i++;
	}
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("mlx_init failed\n", game);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "The Maze");
	if (!game->win)
		error_exit("mlx_new_window failed\n", game);
	load_frame(game, &game->graphics->frame);
	load_hand(game, &game->graphics->hand_r, "textures/hand_r.xpm");
	load_hand(game, &game->graphics->hand_l, "textures/hand_l.xpm");
	load_textures(game, game->graphics->wall_img);
}
