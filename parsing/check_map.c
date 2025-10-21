/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:26:52 by skayed            #+#    #+#             */
/*   Updated: 2025/10/21 15:44:28 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// static int	is_closed(char **map)
// {
// 	int	i;
// 	int	len_row;
// 	int	last_row;

// 	i = 0;
// 	last_row = 0;
// 	while (map[last_row] != NULL)
// 		last_row++;
// 	last_row--;
// 	while (map[i])
// 	{
// 		len_row = 0;
// 		while (map[i][len_row])
// 		{
// 			if ((i == 0 || i == last_row) && map[i][len_row] != '1')
// 				return (ft_printf("Error:\nThe map must be closed\n"), -1);
// 			len_row++;
// 		}
// 		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
// 			return (ft_printf("Error:\nThe map must be closed\n"), -1);
// 		i++;
// 	}
// 	return (0);
// }

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
	//flood_fill(map);
	return (0);
}
