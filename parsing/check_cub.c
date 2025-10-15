/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:25:17 by skayed            #+#    #+#             */
/*   Updated: 2025/10/15 12:56:01 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_gstruct(t_graphics *graphics)
// controlla se manca qualche info grafica
{
	int i;

	i = 0;
	while (i < TEX_COUNT)
	{
		if (!graphics->paths[i] || graphics->paths[i] == NULL)
			return (-1);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (graphics->floor[i] == -1 || graphics->ceiling[i] == -1)
			return (-1);
		i++;
	}
	return (1);
}

static int	parse_textures(char *line, t_graphics *graphics)
{
	int		i;
	char	*refined;

	i = 0;
	while (i < TEX_COUNT)
	{
		if (!ft_strncmp(line, graphics->flags[i], 2))
		{
			if (graphics->paths[i] != NULL) //duplicato
				return (-1);
			line += 2;
			if (*line != ' ' && *line != '\t')
				return (-1);
			if (*line == '\0')
				return (-1);
			refined = clean_line(line);
			if (!refined)
				return (-1);
			if (check_path(refined)) // se file ha estensione giusta e se si riesce ad aprire
				graphics->paths[i] = refined;
			else
				return (-1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_cub(t_game *game)
{
	int		fd;
	char	*line;
	char	*trimmed;
	int		i;

	fd = open(game->map->filename, O_RDONLY);
	if (fd == -1)
		return (error_exit("Open file failed", game), -1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		trimmed = ft_strtrim(line, "\n"); // trim e salta righe con solo \n
		free(line);
		line = clean_line(trimmed);
		free(trimmed);
		if (!line || *line == '\0')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (!game->map->in_map && trimmed)
		{
			line = clean_line(trimmed);
			free(trimmed);
			i = 0;
			while (i < TEX_COUNT) // controllo se line contiene texture
			{
				if (!ft_strncmp(line, game->graphics->flags[i], 2))
					if (parse_textures(line, game->graphics) < 0)
						return (ft_close("Textures not valid", line, fd, game),
								-1);
				i++;
			}
			if (!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
				if (parse_rgb(line, game) < 0)
					return (ft_close("RGB not valid", line, fd, game), -1);
			free(line);
		}
		else if (game->map->in_map && trimmed) // siamo nella mappa
		{
			if (check_gstruct(game->graphics))
				// controlla se manca qualche info grafica
				if (check_map(trimmed, game) < 0)
					return (ft_close("Map not valid", trimmed, fd, game),
							-1);
				else
					return (ft_close("File .cub not valid", trimmed, fd, game),
							-1);
		}
		else
			return (ft_close("File .cub not valid", trimmed, fd, game), -1);
		free(trimmed);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
