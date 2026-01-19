/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:25:17 by skayed            #+#    #+#             */
/*   Updated: 2026/01/15 14:55:21 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	handle_map_line(char **line, t_game *game, int fd)
{
	int	status;

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

static void	read_check(char **line, int fd, t_game *game)
{
	char	*trimmed;

	trimmed = ft_strtrim(*line, "\n");
	free(*line);
	if (!trimmed)
		error_exit("Malloc failed", game);
	*line = trimmed;
	if (handle_map_line(line, game, fd) > 0)
		return ;
	trimmed = clean_line(*line);
	free(*line);
	*line = trimmed;
	if (*line == NULL || *(*line) == '\0')
	{
		free(*line);
		*line = get_next_line(fd);
		return ;
	}
	if (handle_config_line(*line, game, fd) <= 0)
		ft_close("Unexpected configuration line", *line, fd, game);
	free(*line);
	*line = get_next_line(fd);
	return ;
}

int	check_cub(t_game *game)
{
	int		fd;
	char	*line;

	fd = open(game->map->filename, O_RDONLY);
	if (fd == -1)
		return (error_exit("Open file failed", game), -1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		read_check(&line, fd, game);
	}
	free(line);
	if (game->map->map == NULL)
		return (error_exit("Map is missing", game), -1);
	return (close(fd), 0);
}
