/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:45:36 by skayed            #+#    #+#             */
/*   Updated: 2025/10/21 15:26:01 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_char(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == '1') || !(line[i] == '0') || !(line[i] == 'N') || !(line[i] == 'S')
			|| !(line[i] == 'E') || !(line[i] == 'W') || !(line[i] == ' '))
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

int	save_map(char *line, t_game *game)
{
	int		i;
	char	**new_map;
	int		rows;

	rows = 0;
	if (!line || *line == '\n')
		return (0);
	if (!check_char(line))
		return (error_exit("Invalid character in map line", game), -1);
	rows = find_last_row(game->map->map);
	new_map = (char **)malloc(sizeof(char *) * (rows + 2));
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
			i++;
		}
	}
	new_map[i] = ft_strdup(line);
	if (!new_map[i])
	{
		free_matrix(new_map);
		return (error_exit("Malloc failed", game), -1);
	}
	new_map[i + 1] = NULL;
	if (game->map->map)
		free_matrix(game->map->map);
	game->map->map = new_map;
	return (1);
}
