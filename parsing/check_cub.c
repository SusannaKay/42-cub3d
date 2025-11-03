/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:25:17 by skayed            #+#    #+#             */
/*   Updated: 2025/11/03 14:46:40 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	handle_map_line(char **line, t_game *game, int fd)
// passo puntatore alla linea per liberare la memoria e non lavorare su una copia
{
	int status;
	status = map_line(*line, game);
	if (!status) 
		return (0);
	if (status < 0)
		return (ft_close("Empty line in map", *line, fd, game), -1);
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
	char	*trimmed;
	int		status;

	fd = open(game->map->filename, O_RDONLY);
	if (fd == -1)
		return (error_exit("Open file failed", game), -1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		trimmed = ft_strtrim(line, "\n");
		free(line);
		if (!trimmed)
			return (error_exit("Malloc failed", game), -1);
		line = trimmed;
		status = handle_map_line(&line, game, fd);
		if (status < 0)
			return (-1);
		if (status > 0)
			continue ;
		trimmed = clean_line(line);
		free(line);
		line = trimmed;
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
	free(line);
	return (close(fd), 0);
}
