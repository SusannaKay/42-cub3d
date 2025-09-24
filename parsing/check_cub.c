/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:25:17 by skayed            #+#    #+#             */
/*   Updated: 2025/09/24 17:20:53 by skayed           ###   ########.fr       */
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
static int	check_textures(t_graphics *graphics)
{
	if (!graphics->no || !graphics->so | !graphics->we | !graphics->ea)
		return (0);
	if (!graphics->floor || !graphics->celing)
		return (0);
	return (1);
}
int	check_cub(t_game *game)
{
	int fd;
	char *line;
	char *pos;

	fd = open(game->map->filename, O_RDONLY);
	if (fd < 0)
		return (error_exit(perror, game));
	line = get_next_line(fd);
	while (fd > 0)
	{
		if (game->map->in_map)
		{
			if (check_textures(game->graphics))
				check_map();
			else
				return(error_exit("File .cub not valid", game));
		}
		else
		{
			if (!check_graphics(line))
				while(line[i])
			{
				se trovi 0, 1 ecc in map break
				else 
					i++;
			}
		}
	}

	if (ft_strnstr(line, "NO"))
	{
		pos = ft_strnstr(line, "NO");
		while (pos)
		{
			if (*pos == '.')
				ft_strdup(pos);
		}
	}
	close(fd);
}