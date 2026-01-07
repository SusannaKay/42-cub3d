/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonacco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:30:47 by ebonacco          #+#    #+#             */
/*   Updated: 2025/12/10 19:30:51 by ebonacco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_tex_x(t_map *map, t_img *tex, double wall_x)
{
	int	tex_x;

	tex_x = (int)(wall_x * tex->w); // pixel orizzontale corrispondente della texture es. wall_x = 0.45, tex->w = 64 → tex_x = (int)(0.45 * 64) ≈ 28;
	if (map->side == 0 && map->ray_x < 0) // serve per leggere la texture dalla fine se e colpita dal lato opposto
		tex_x = tex->w - tex_x - 1; // !!!!!!! tex_x e utilizzato come indice in realta (get_pixel(wall->tex, wall->tex_x, tex_y)
	if (map->side == 1 && map->ray_y > 0)
		tex_x = tex->w - tex_x - 1; // - 1 ncessario in entrambi i casi perche i pixel partono da 0
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
	double	wall_x; // coordinata reale del muro

	if (map->side == 0)
		wall_x = map->p_y + (map->ray_y * dist); // cioe se il muro e verticale (va pensato come se stessimo guardando la mappa dall'alto) la coordinata x non cambia mentre quella y si e sara il riferimento per la x della texture
	else
		wall_x = map->p_x + (map->ray_x * dist);
	return (wall_x - floor(wall_x)); // si riduce ad un offset tra 0 e 1 per il terxture mapping, si puo anche castare a int in questo caso perche consideriamo solo i valori positivi
}

void	init_wall(t_game *game, t_wall *wall, int x, double dist)
{
	double	wall_x;

	wall->x = x; // !!!!!!! valore recuperato in put pixel
	wall->line_h = (int)(HEIGHT / dist); // questo perche se l adistanza e 1 allora l'altezza del muro e uguale a HEIGHT e occupa tutto lo schermo
	height_limits(wall->line_h, &wall->start, &wall->end);
	wall_x = get_wall_x(game->map, dist);
	wall->tex = &game->graphics->wall_img[get_tex_id(game->map)];
	wall->tex_x = get_tex_x(game->map, wall->tex, wall_x);
}
