
#include "../includes/cub3d.h"

static char	*read_clean_line(int fd, t_game *game)
{
	char	*line;
	char	*tmp;

	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strtrim(line, "\n");
		free(line);
		if (!tmp)
			return (error_exit("Malloc failed", game), NULL);
		line = clean_line(tmp);
		free(tmp);
		if (!line)
			return (error_exit("Malloc failed", game), NULL);
		if (*line != '\0')
			return (line);
		free(line);
		line = get_next_line(fd);
	}
	return (NULL);
}

static int	is_texture_line(char *line, t_game *game, int *idx)
{
	int	i;

	i = 0;
	while (i < TEX_COUNT)
	{
		if (!ft_strncmp(line, game->graphics->flags[i], 2))
			return (*idx = i, 1);
		i++;
	}
	return (0);
}

static int	is_rgb_line(char *line)
{
	return (!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1));
}

static int	handle_config_line(char *line, t_game *game, int fd)
{
	int	idx;

	if (is_texture_line(line, game, &idx))
	{
		if (parse_textures(line, game->graphics) < 0)
			return (ft_close("Textures not valid", line, fd, game), -1);
		return (1);
	}
	if (is_rgb_line(line))
	{
		if (parse_rgb(line, game) < 0)
			return (ft_close("RGB not valid", line, fd, game), -1);
		return (1);
	}
	return (0);
}

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
	*line = read_clean_line(fd, game);
	return (1);
}

int	check_cub(t_game *game)
{
	int		fd;
	char	*line;
	int		status;

	fd = open(game->map->filename, O_RDONLY);
	if (fd == -1)
		return (error_exit("Open file failed", game), -1);
	line = read_clean_line(fd, game);
	while (line)
	{
		status = handle_map_line(&line, game, fd);
		if (status < 0)
			return (-1);
		if (status > 0)
			continue ;
		if (handle_config_line(line, game, fd) <= 0)
			return (ft_close("Unexpected configuration line", line, fd, game),
					-1);
		free(line);
		line = read_clean_line(fd, game);
	}
	return (close(fd), 0);
}
