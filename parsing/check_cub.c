/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:25:17 by skayed            #+#    #+#             */
/*   Updated: 2025/09/24 15:11:59 by skayed           ###   ########.fr       */
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



int	check_cub(char *filename)
{
	int fd;
	char *line;
	char *pos;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (exit);
	line = get_next_line(fd);
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