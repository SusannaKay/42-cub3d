/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:57:26 by skayed            #+#    #+#             */
/*   Updated: 2026/01/19 14:40:19 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->map)
	{
		i = 0;
		while (map->map[i])
		{
			free(map->map[i]);
			map->map[i] = NULL;
			i++;
		}
		free(map->map);
		map->map = NULL;
	}
	free(map);
}

void	free_graphics(t_graphics *graphics, void *mlx)
{
	int	i;

	if (!graphics)
		return ;
	i = 0;
	while (i < TEX_COUNT)
	{
		if (graphics->paths[i])
		{
			free(graphics->paths[i]);
			graphics->paths[i] = NULL;
		}
		if (graphics->wall_img[i].img)
			mlx_destroy_image(mlx, graphics->wall_img[i].img);
		i++;
	}
	if (graphics->frame.img)
		mlx_destroy_image(mlx, graphics->frame.img);
	if (graphics->hand_r.img)
		mlx_destroy_image(mlx, graphics->hand_r.img);
	if (graphics->hand_l.img)
		mlx_destroy_image(mlx, graphics->hand_l.img);
	free(graphics);
}

static void	destroy_mlx(t_game *game)
{
	mlx_loop_end(game->mlx);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	game->mlx = NULL;
}

void	free_all(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
	{
		free_map(game->map);
		game->map = NULL;
	}
	if (game->graphics)
	{
		free_graphics(game->graphics, game->mlx);
		game->graphics = NULL;
	}
	if (game->keys)
	{
		free(game->keys);
		game->keys = NULL;
	}
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
		destroy_mlx(game);
	free(game);
}

int	exit_destroy(t_game *game)
{
	if (game)
		free_all(game);
	exit(0);
	return (0);
}
