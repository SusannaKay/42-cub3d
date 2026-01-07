/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:46:19 by ebonacco          #+#    #+#             */
/*   Updated: 2026/01/07 13:39:33 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotation(t_map *map, double old_dir_x, double rotation)
{
	map->dir_x = map->dir_x * cos(rotation) - map->dir_y * sin(rotation);
	map->dir_y = old_dir_x * sin(rotation) + map->dir_y * cos(rotation);
}

void	rotations(t_game *game)
{
	double	old_dir_x;

	old_dir_x = game->map->dir_x;
	if (game->keys->left)
		rotation(game->map, old_dir_x, -ROTATION);
	if (game->keys->right)
		rotation(game->map, old_dir_x, ROTATION);
}

void	move(t_map *map, double dir_x, double dir_y)
{
	double	new_p_x;
	double	new_p_y;

	new_p_x = map->p_x + dir_x * MOVE;
	new_p_y = map->p_y + dir_y * MOVE;
	if ((map->map[(int)map->p_y][(int)(new_p_x + dir_x * COLLISION)]) != '1')
		map->p_x = new_p_x;
	if ((map->map[(int)(new_p_y + dir_y * COLLISION)][(int)map->p_x]) != '1')
		map->p_y = new_p_y;
}

void	moves(t_game *game)
{
	if (game->keys->w)
		move(game->map, game->map->dir_x, game->map->dir_y);
	else if (game->keys->s)
		move(game->map, -game->map->dir_x, -game->map->dir_y);
	else if (game->keys->a)
		move(game->map, -game->map->plane_x, -game->map->plane_y);
	else if (game->keys->d)
		move(game->map, game->map->plane_x, game->map->plane_y);
}
