/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:45:36 by skayed            #+#    #+#             */
/*   Updated: 2025/10/20 18:24:14 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	find_last_row(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (-1);
	printf("Finding last row of the map.\n");
	while (map[i])
		i++;
	return (i - 1);
}

int	save_map(char *line, t_game *game)
{
	int		i;
	char	**new_map;
	int		rows;

	rows = 0;
	if (!line || *line == '\n')
		return (0);
	i = 0;
	i = find_last_row(game->map->map);
	printf("Current map has %d rows. Preparing to add new row.\n", i);
	new_map = (char **)malloc(sizeof(char *) * (i + 2));
	printf("Allocated memory for %d rows.\n", (i + 2));
	if (!new_map)
		return (error_exit("Malloc failed", game), -1);
	while (rows < i)
	{
		new_map[rows] = game->map->map[rows];
		printf("Copied existing map row %d: %s\n", rows, new_map[rows]);
		rows++;
	}
	new_map[rows] = ft_strdup(line);
	printf("Duplicated line into new map row: %s\n", new_map[rows]);
	if (!new_map[rows])
	{
		free(new_map);
		return (error_exit("Malloc failed", game), -1);
	}
	new_map[rows + 1] = NULL;
	free(game->map->map);
	game->map->map = new_map;
	return (1);
}
