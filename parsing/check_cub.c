/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:25:17 by skayed            #+#    #+#             */
/*   Updated: 2025/10/20 18:28:03 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	handle_map_line(char **line, t_game *game, int fd)
// passo puntatore alla linea per liberare la memoria e non lavorare su una copia
{
	printf("Checking if line is part of the map: %s\n", *line);
	if (!map_line(*line, game))
		return (0);
	if (check_gstruct(game->graphics) < 0)
		return (ft_close("Missing textures/colors before map", *line, fd, game),
				-1);
	if (save_map(*line, game) < 0)
		return (ft_close("Map not valid", *line, fd, game), -1);
	free(*line);
	*line = get_next_line(fd);
	return (1);
}

static int	handle_config_line(char *line, t_game *game, int fd)
{
	int	i;

	i = 0;
	while (i < TEX_COUNT)
	{
		printf("Checking if line is texture config for %s: %s\n",
			game->graphics->flags[i], line);
		if (!ft_strncmp(line, game->graphics->flags[i], 2))
		{
			if (parse_textures(line, game->graphics) < 0)
				return (ft_close("Textures not valid", line, fd, game), -1);
			return (1);
		}
		i++;
	}
	if (!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
	{
		if (parse_rgb(line, game) < 0)
			return (ft_close("RGB not valid", line, fd, game), -1);
		return (1);
	}
	return (0);
}

int	check_cub(t_game *game)
{
	int		fd;
	char	*line;
	char	*tmp;
	int		status;

	fd = open(game->map->filename, O_RDONLY);
	if (fd == -1)
		return (error_exit("Open file failed", game), -1);
	line = get_next_line(fd);
	printf("Reading file line: %s \n", line);
	while (line != NULL)
	{
		status = handle_map_line(&line, game, fd);
		printf("handle_map_line status: %d\n", status);
		if (status < 0)
			return (-1);
		if (status > 0)
			continue ;
		tmp = ft_strtrim(line, "\n");
		printf("Reading file line: %s \n", tmp);
		free(line);
		line = clean_line(tmp);
		printf("Reading file line: %s \n", line);
		free(tmp);
		if (!line || *line == '\0')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (handle_config_line(line, game, fd) <= 0)
			return (ft_close("Unexpected configuration line", line, fd, game),
					-1);
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 0);
}
