/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:25:17 by skayed            #+#    #+#             */
/*   Updated: 2025/09/30 16:38:15 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// apri file
// NON SI APRE : file does not exist -> perror
// SI APRE :
//GETNEXTLINE FINO A 0
// E' IN MAP
// CHECK TEXTURE E COLORI
// NON CI SONO --> Error
// CI SONO CHECK MAPPA

// NON E' IN MAP
// CHECK PER OGNI TEXTURE
// ESISTE GIA'? --> Error
// NON ESISTE --> ADD
// CHECK FLOOR E CEILING
// ESISTE GIA? --> Error
// CHECK VALORI TRA 0 E 255
// CHECK 3 VALORI
// AGGIUNGI AD ARRAY
static int	check_gstruct(t_graphics *graphics)
{
	int	i;

	i = 0;
	while (i < TEX_COUNT)
	{
		if (!graphics->paths[i] || graphics->paths[i] == NULL)
			return (-1);
		i++;
	}
	// manca check floor e ceiling
	return (0);
}

static int	parse_textures(char *line, t_graphics *graphics)
{
	int	i;

	i = 0;
	line = check_line(line);
	if(!line)
		return (0);
	while (i < TEX_COUNT)
	{
		if (!ft_strncmp(line, graphics->flags[i], 2))
		{
			line += 2;
			while (*line)
			{
				if (*line != ' ')
				{
					if (graphics->paths[i] != NULL)
						return (-1); // duplicato
					graphics->paths[i] = ft_strdup(line);
					if (!graphics->paths[i])
						return (-1); // malloc
					return (1);
				}
				line++;
			}
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

	fd = open(game->map->filename, O_RDONLY);
	if (fd == -1)
		return (error_exit("Open file failed", game), -1);
	line = get_next_line(fd);
	while (fd > 0)
	{
		trimmed = ft_strtrim(line, "\n");
		free(line);
		if (game->map->in_map)
		{
			if (check_gstruct(game->graphics))
				// controlla se manca qualche info grafica
				check_map();
			else
				return (error_exit("File .cub not valid", game), -1);
		}
		else // non stiamo nella mappa
		{
			if (parse_textures(trimmed, game->graphics) < 0)
				return (error_exit("File .cub not valid", game), -1);	
		}
		free(trimmed);
		line = get_next_line(fd);
	}
	close(fd);
}

if (!check_graphics(line))
	while (line[i])
	{
		se trovi 0, 1 ecc in map break else i++;
	}