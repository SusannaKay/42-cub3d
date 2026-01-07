/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:30:47 by ebonacco          #+#    #+#             */
/*   Updated: 2026/01/07 15:10:44 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_tex_x(t_map *map, t_img *tex, double wall_x)
{
	int	tex_x;

	tex_x = (int)(wall_x * tex->w);
	if (map->side == 0 && map->ray_x < 0)
		tex_x = tex->w - tex_x - 1;
	if (map->side == 1 && map->ray_y > 0)
		tex_x = tex->w - tex_x - 1;
	return (tex_x);
}

int	get_tex_id(t_map *map)
{
	if (map->side == 0)
	{
		if (map->ray_x > 0)
			return (TEX_EA);
		return (TEX_WE);
	}
	else
	{
		if (map->ray_y > 0)
			return (TEX_SO);
		return (TEX_NO);
	}
}

double	get_wall_x(t_map *map, double dist)
{
	double	wall_x;

	if (map->side == 0)
		wall_x = map->p_y + (map->ray_y * dist);
	else
		wall_x = map->p_x + (map->ray_x * dist);
	return (wall_x - floor(wall_x));
}

void	init_wall(t_game *game, t_wall *wall, int x, double dist)
{
	double	wall_x;

	wall->x = x;
	wall->line_h = (int)(HEIGHT / dist);
	height_limits(wall->line_h, &wall->start, &wall->end);
	wall_x = get_wall_x(game->map, dist);
	wall->tex = &game->graphics->wall_img[get_tex_id(game->map)];
	wall->tex_x = get_tex_x(game->map, wall->tex, wall_x);
}
