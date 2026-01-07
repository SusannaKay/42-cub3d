/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonacco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:22:54 by ebonacco          #+#    #+#             */
/*   Updated: 2025/12/16 17:22:57 by ebonacco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	height_limits(int line_h, int *start, int *end)
{
	*start = HEIGHT / 2 - line_h / 2; // serve per centrare il muro
	*end = HEIGHT / 2 + line_h / 2;
	if (*start < 0) // assicura che i pixel non escano fuori dal framebuffer
		*start = 0;
	if (*end >= HEIGHT)
		*end = HEIGHT - 1;
}

double	distance(t_map *map)
{
	if (map->side == 0)
		return (map->side_x - map->delta_x);
	else
		return (map->side_y - map->delta_y);
}

void	find_plane(t_map *map)
{
	double	fov_factor;

	fov_factor = 0.66; // esprime l'angolo dell'ampiezza della visuale
	map->plane_x = -map->dir_y * fov_factor; // attenzione al segno negativo, serve per selezionare la direzione del plane di sinistra perche i raggi sono incrementati dal bordo sinistro a quello destro
	map->plane_y = map->dir_x * fov_factor;
}

void	raycast(t_game *game)
{
	int		i;
	double	camera_x;
	t_wall	wall;

	i = 0;
	find_plane(game->map);
	while (i < WIDTH)
	{
		camera_x = (2.0 * i / WIDTH) - 1.0; // valore normalizzato tra -1 e 1 serve a calcolare la direzione del raggio in base alla posizione della colonna sullo schermo
		init_ray(game->map, camera_x);
		draw_world(game, i);
		init_wall(game, &wall, i, distance(game->map));
		draw_texture(game, &wall);
		i++;
	}
	draw_hand(game, &game->graphics->hand_r, WIDTH - game->graphics->hand_r.w,
		HEIGHT - game->graphics->hand_r.h);
	draw_hand(game, &game->graphics->hand_l, 0,
		HEIGHT - game->graphics->hand_l.h);
}
