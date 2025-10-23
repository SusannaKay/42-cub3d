/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:26:52 by skayed            #+#    #+#             */
/*   Updated: 2025/10/23 17:17:54 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int check_directions(char **map, int x, int y)
{
	if ((map[y - 1][x] == ' ' || map[y + 1][x] == ' ' ||
		map[y][x - 1] == ' ' || map[y][x + 1] == ' '))
		return (-1);
	return (1);
}

static int is_closed(char **map)
{
	int i;
	int j;
	
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'E' || map[i][j] == 'W')
				{
					if (check_directions(map, j, i) < 0)
						return (0);
				}
			j++;
		}
		i++;
	}
	return (1);
}

static int	process_cell(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'N' || map->map[i][j] == 'S' ||
		map->map[i][j] == 'E' || map->map[i][j] == 'W')
	{
		if (!map->p_counter)
		{
			map->p_counter++;
			map->p_x = j;
			map->p_y = i;
			map->p_dir = map->map[i][j];
		}
		else
			return (-1);
	}
	return (0);
}

static int	check_player(t_game *game)
{
	int	i;
	int	j;
	t_map	*map;

	i = 0;
	map = game->map;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (process_cell(map, i, j) < 0)
				return (error_exit("Too many Player", game), -1);
			j++;
		}
		i++;
	}
	if (map->p_counter == 0)
		return (error_exit("Missing Player.\n", game), -1);
	return (0);
}

void	verify_map(t_game *game)
{
	check_player(game);
	if (!is_closed(game->map->map))
		error_exit("Map is not closed.\n", game);
}
