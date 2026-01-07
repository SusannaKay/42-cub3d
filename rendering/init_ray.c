/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonacco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:49:43 by ebonacco          #+#    #+#             */
/*   Updated: 2025/12/10 17:50:39 by ebonacco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
delta_x / delta_y = distanza necessaria per attraversare 1 cella in X o Y
side_x / side_y = distanza cumulativa del raggio fino alla prossima linea di griglia
step_x / step_y = direzione del raggio nella griglia (+1 o -1)
distance = distanza reale dal player alla parete colpita
plane = piano di proiezione per disegnare la scena 3D
*/

/* DDA
partiamo dalla cella dove si trova il player (map_x, map_y)
loop fino a colpire un muro (hit = 1)
ad ogni passo:
confronta side_x e side_y e decide se avanzare lungo X o Y
aggiorna map_x e map_y di un passo (step_x e step_y)
aggiorna side_x e side_y
controlla se la nuova cella e un muro e ferma la DDA
*/
void	dda(t_map *map)
{
	int		map_x;
	int		map_y;
	char	c;

	map_x = (int)map->p_x;
	map_y = (int)map->p_y;
	while (!map->hit)
	{
		if (map->side_x < map->side_y) // confronta side_x e side_y e decide se avanzare lungo X o Y
		{
			map->side_x += map->delta_x; // aggiorna side_x e side_y
			map_x += map->step_x; // aggiorna map_x e map_y di un passo (step_x e step_y)
			map->side = 0; // indica se il muro e orizzontale o verticale
		}
		else
		{
			map->side_y += map->delta_y; // aggiorna side_x e side_y
			map_y += map->step_y; // aggiorna map_x e map_y di un passo (step_x e step_y)
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
		map->side_x = (map->p_x - (int)map->p_x) * map->delta_x; // se il raggio punta a sinistra si casta a int perche rappresenta la cella in cui si trova il player, quindi rappresenta la distanza tra player e bordo di sinistra o bordo superiore
	else
		map->side_x = ((int)map->p_x + 1.0 - map->p_x) * map->delta_x; // se il raggio punta a destra per calcolare il residuo della cella e necessario aggiungere semplicemente 1 prima di sottrarre il valore del player
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
	map->hit = 0; // serve solo per resettare il valore di hit a ogni calcolo
	init_side(map);
}

void	init_delta(t_map *map)
{
	if (map->ray_x < 0)
		map->delta_x = 1.0 / map->ray_x * -1; // * -1 serve solo a far diventare positivo il delta perché la DDA lavora con distanze positive
	else
		map->delta_x = 1.0 / map->ray_x;
	if (map->ray_y < 0)
		map->delta_y = 1.0 / map->ray_y * -1; // * -1 serve solo a far diventare positivo il delta perché la DDA lavora con distanze positive
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
