/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:23:31 by skayed            #+#    #+#             */
/*   Updated: 2025/09/23 16:47:18 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_graphics	*init_graphics(t_graphics *graphics)
{
	graphics = malloc(sizeof(t_graphics));
	if (!graphics)
		return (NULL);
	graphics->no = NULL;
	graphics->so = NULL;
	graphics->we = NULL;
	graphics->ea = NULL;
	graphics->floor = NULL;
	graphics->ceiling = NULL;
	return (graphics);
}

t_map	*init_map(t_map *map)
{
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = NULL;
	map->filename = NULL;
	map->p_x = 0;
	map->p_y = 0;
	map->p_orient = 'a';
	return (map);
}

t_game	*init_game(t_game *game)
{
	t_graphics *graphics;
	
	graphics = init_graphics(graphics);
	(!graphics) return (NULL);
	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx = mlx_init();
	game->win = mlx_new_window(mlx->mlx, 300, 300, "The Maze");
	game->graphics = graphics;
	game->map = NULL;
	return (game);
}