/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:23:31 by skayed            #+#    #+#             */
/*   Updated: 2025/09/24 16:15:24 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_map	*init_map(t_map *map)
{
	map = malloc(sizeof(t_map));
	if (!map)
		return (error_exit(perror, NULL));
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

	graphics = ft_calloc(1, sizeof(t_graphics));
	if (!graphics)
		return (error_exit(perror, NULL), NULL);
	game->graphics = graphics;
	game->mlx = mlx_init();
	game->win = mlx_new_window(mlx->mlx, 300, 300, "The Maze");
	return (game);
}