/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:23:31 by skayed            #+#    #+#             */
/*   Updated: 2026/01/08 12:15:53 by skayed           ###   ########.fr       */
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
	graphics->line_len = 0;
}

void	init_map_defaults(t_map *map)
{
	if (!map)
		return ;
	map->map = NULL;
	map->in_map = 0;
	map->p_counter = 0;
	map->p_x = -1;
	map->p_y = -1;
	map->p_dir = '\0';
	map->ray_x = 0;
	map->ray_y = 0;
	map->dir_x = 0;
	map->dir_y = 0;
	map->plane_x = 0;
	map->plane_y = 0;
	map->step_x = 0;
	map->step_y = 0;
	map->side_x = 0;
	map->side_y = 0;
	map->delta_x = 0;
	map->delta_y = 0;
	map->hit = -1;
	map->side = -1;
}

static void	init_img_defaults(t_img wall_img[TEX_COUNT])
{
	int	i;

	i = 0;
	while (i < TEX_COUNT)
	{
		wall_img[i].img = NULL;
		wall_img[i].addr = NULL;
		wall_img[i].bit_pp = 0;
		wall_img[i].line_len = 0;
		wall_img[i].endian = 0;
		wall_img[i].w = 0;
		wall_img[i].h = 0;
		i++;
	}
}

void	init_keys_defaults(t_keys *keys)
{
	if (!keys)
		return ;
	keys->w = 0;
	keys->s = 0;
	keys->a = 0;
	keys->d = 0;
	keys->left = 0;
	keys->right = 0;
}

t_game	*init_game(t_game **game)
{
	(*game)->mlx = NULL;
	(*game)->win = NULL;
	(*game)->graphics = ft_calloc(1, sizeof(t_graphics));
	if (!(*game)->graphics)
		return (error_exit("Malloc failed", (*game)), NULL);
	init_graphics_defaults((*game)->graphics);
	init_img_defaults((*game)->graphics->wall_img);
	(*game)->map = ft_calloc(1, sizeof(t_map));
	if (!(*game)->map)
		return (error_exit("Malloc failed", (*game)), NULL);
	init_map_defaults((*game)->map);
	(*game)->keys = ft_calloc(1, sizeof(t_keys));
	if (!(*game)->keys)
		return (error_exit("Malloc failed", (*game)), NULL);
	init_keys_defaults((*game)->keys);
	return (*game);
}
