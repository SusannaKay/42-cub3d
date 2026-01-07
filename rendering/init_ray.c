/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:49:43 by ebonacco          #+#    #+#             */
/*   Updated: 2026/01/07 15:13:34 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	dda(t_map *map)
{
	int		map_x;
	int		map_y;
	char	c;

	map_x = (int)map->p_x;
	map_y = (int)map->p_y;
	while (!map->hit)
	{
		if (map->side_x < map->side_y)
		{
			map->side_x += map->delta_x;
			map_x += map->step_x;
			map->side = 0;
		}
		else
		{
			map->side_y += map->delta_y;
			map_y += map->step_y;
			map->side = 1;
		}
		c = map->map[map_y][map_x];
		if (c == '1')
			map->hit = 1;
	}
}

void	init_side(t_map *map)
{
	if (map->step_x == -1)
		map->side_x = (map->p_x - (int)map->p_x) * map->delta_x;
	else
		map->side_x = ((int)map->p_x + 1.0 - map->p_x) * map->delta_x;
	if (map->step_y == -1)
		map->side_y = (map->p_y - (int)map->p_y) * map->delta_y;
	else
		map->side_y = ((int)map->p_y + 1.0 - map->p_y) * map->delta_y;
	dda(map);
}

void	init_step(t_map *map)
{
	if (map->ray_x < 0)
		map->step_x = -1;
	else
		map->step_x = 1;
	if (map->ray_y < 0)
		map->step_y = -1;
	else
		map->step_y = 1;
	map->hit = 0;
	init_side(map);
}

void	init_delta(t_map *map)
{
	if (map->ray_x < 0)
		map->delta_x = 1.0 / map->ray_x * -1;
	else
		map->delta_x = 1.0 / map->ray_x;
	if (map->ray_y < 0)
		map->delta_y = 1.0 / map->ray_y * -1;
	else
		map->delta_y = 1.0 / map->ray_y;
	init_step(map);
}

void	init_ray(t_map *map, double camera_x)
{
	map->ray_x = map->dir_x + map->plane_x * camera_x;
	map->ray_y = map->dir_y + map->plane_y * camera_x;
	init_delta(map);
}
