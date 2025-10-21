/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:45:36 by skayed            #+#    #+#             */
/*   Updated: 2025/10/21 14:06:08 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	find_last_row(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	printf("Finding last row of the map.\n");
	while (map[i])
		i++;
	return (i);
}

int	save_map(char *line, t_game *game)
{
	int		i;
	char	**new_map;
	int		rows;

	rows = 0;
	if (!line || *line == '\n')
		return (0);
	rows = find_last_row(game->map->map);
	printf("Current map has %d rows. Preparing to add new row.\n", i);
	new_map = (char **)malloc(sizeof(char *) * (rows + 2));
	printf("Allocated memory for %d rows.\n", (rows + 2));
	if (!new_map)
		return (error_exit("Malloc failed", game), -1);
	i = 0;
	if (game->map->map)
	{
		while (i < rows)
		{
			new_map[i] = ft_strdup(game->map->map[i]);
			if (!new_map[i])
			{
				free_matrix(new_map);
				return (error_exit("Malloc failed", game), -1);
			}
			printf("Copied existing map row %d: %s\n", i, new_map[i]);
			i++;
		}
	}
	new_map[i] = ft_strdup(line);
	if (!new_map[i])
	{
		free_matrix(new_map);
		return (error_exit("Malloc failed", game), -1);
	}
	printf("Duplicated line into new map row: %s\n", new_map[rows]);
	new_map[i + 1] = NULL;
	if (game->map->map)
		free_matrix(game->map->map);
	game->map->map = new_map;
	return (1);
}
