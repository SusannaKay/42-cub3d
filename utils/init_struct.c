/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:23:31 by skayed            #+#    #+#             */
/*   Updated: 2025/10/20 16:07:31 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_graphics_defaults(t_graphics *graphics)
{
	if (!graphics)
		return ;
	graphics->flags[TEX_NO] = "NO";
	graphics->flags[TEX_SO] = "SO";
	graphics->flags[TEX_WE] = "WE";
	graphics->flags[TEX_EA] = "EA";
	graphics->floor[0] = -1;
	graphics->floor[1] = -1;
	graphics->floor[2] = -1;
	graphics->ceiling[0] = -1;
	graphics->ceiling[1] = -1;
	graphics->ceiling[2] = -1;
}

static void	init_map_defaults(t_map *map)
{
	if (!map)
		return ;
	map->map = NULL;
	map->in_map = 0;
	map->height = 0;
	map->width = 0;
}

t_game	*init_game(t_game **game)
{
	printf("Allocating game struct\n");
	(*game)->mlx = NULL;
	(*game)->win = NULL;
	printf("Allocating graphics struct\n");
	(*game)->graphics = ft_calloc(1, sizeof(t_graphics));
	if (!(*game)->graphics)
		return (error_exit("Malloc failed", (*game)), NULL);
	init_graphics_defaults((*game)->graphics);
	(*game)->map = ft_calloc(1, sizeof(t_map));
	if (!(*game)->map)
		return (error_exit("Malloc failed", (*game)), NULL);
	printf("Allocating map struct\n");
	init_map_defaults((*game)->map);
	printf("Allocating player struct\n");
	(*game)->player = ft_calloc(1, sizeof(t_player));
	if (!(*game)->player)
		return (error_exit("Malloc failed", (*game)), NULL);
	//game->mlx = mlx_init();
	// if (!game->mlx)
	// 	return (error_exit("mlx_init failed", game), NULL);
	// game->win = mlx_new_window(game->mlx, 300, 300, "The Maze");
	// if (!game->win)
	// 	return (error_exit("mlx_new_window failed", game), NULL);
	return ((*game));
}
