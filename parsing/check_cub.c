/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:25:17 by skayed            #+#    #+#             */
/*   Updated: 2025/10/16 15:02:13 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_cub(t_game *game)
{
	int		fd;
	char	*line;
	char	*tmp;
	int		i;

	fd = open(game->map->filename, O_RDONLY);
	if (fd == -1)
		return (error_exit("Open file failed", game), -1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (map_line(line, game) && check_gstruct(game->graphics)) // se line fa parte della mappa ( contiene 1 o 0 )imposta in_map
		{
			if (save_map(line, game) < 0) // salva la riga nella matrice map
				return (ft_close("Map not valid", line, fd, game), -1);
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		else
			return (ft_close("File .cub not valid", line, fd, game),
					-1);
		tmp = clean_line(ft_strtrim(line, "\n"));
		free(line);
		if (!tmp || *tmp == '\0')
		{
			free(tmp);
			line = get_next_line(fd);
			continue ;
		}
		i = 0;
		while (i < TEX_COUNT) // controllo se line contiene texture
		{
			if (!ft_strncmp(tmp, game->graphics->flags[i], 2))
				if (parse_textures(tmp, game->graphics) < 0)
					return (ft_close("Textures not valid", tmp, fd, game), -1);
			i++;
		}
		if (!ft_strncmp(tmp, "F", 1) || !ft_strncmp(tmp, "C", 1))
			if (parse_rgb(tmp, game) < 0)
				return (ft_close("RGB not valid", tmp, fd, game), -1);
		free(tmp);
		line = get_next_line(fd);
	}
	return (close(fd), 0);
}
