/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:45:36 by skayed            #+#    #+#             */
/*   Updated: 2025/10/16 14:53:10 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int find_last_row(char **map)
{
	int i = 0;

	if (!map)
		return -1;
	while (map[i])
		i++;
	return i - 1;
}

int	save_map(char *line, t_game *game)
{
	int		i;
	char	**new_map;

	if (!line || *line == '\n')
		return (0);
	if (map_line(line, NULL) == 0) // se non contiene caratteri mappa
		return (-1);
	i = 0;
	i = find_last_row(game->map->map);
	new_map = malloc(sizeof(char *) * (i + 2));
	if (!new_map)
		return (error_exit("Malloc failed", game), -1);
	i = 0;
	i = find_last_row(game->map->map);
	new_map[i] = ft_strdup(line);
	if (!new_map[i])
	{
		free(new_map);
		return (error_exit("Malloc failed", game), -1);
	}
	new_map[i + 1] = NULL;
	free(game->map->map);
	game->map->map = new_map;
	return (1);
}
