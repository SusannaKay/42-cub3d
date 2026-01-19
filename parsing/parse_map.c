/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:45:36 by skayed            #+#    #+#             */
/*   Updated: 2026/01/19 10:39:20 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	find_last_row(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i])
		i++;
	return (i);
}

static char	**copy_map(t_game *game, char *line, int rows)
{
	int		i;
	char	**new_map;

	new_map = (char **)malloc(sizeof(char *) * (rows + 2));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		new_map[i] = ft_strdup(game->map->map[i]);
		if (!new_map[i])
			return (free_matrix(new_map), NULL);
		i++;
	}
	new_map[i] = ft_strdup(line);
	if (!new_map[i])
		return (free_matrix(new_map), NULL);
	new_map[i + 1] = NULL;
	return (new_map);
}

int	save_map(char *line, t_game *game)
{
	char	**new_map;
	int		rows;

	if (!line || *line == '\0')
		return (0);
	if (!check_line(line))
		return (error_exit("Invalid character in map line\n", game), -1);
	rows = find_last_row(game->map->map);
	new_map = copy_map(game, line, rows);
	if (!new_map)
		return (error_exit("Malloc failed\n", game), -1);
	if (game->map->map)
		free_matrix(game->map->map);
	game->map->map = new_map;
	return (1);
}
