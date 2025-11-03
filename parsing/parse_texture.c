/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:37:25 by skayed            #+#    #+#             */
/*   Updated: 2025/11/03 12:47:56 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// controlla se l'estensione e' giusta e se e' possibile aprirle il file grafico

static int	check_path(char *line)
{
	int	len;
	int	fd;

	if (!line)
		return (-1);
	len = ft_strlen(line);
	if (len < 4 || ft_strncmp(line + len - 4, ".xpm", 4) != 0)
		return (-1);
	fd = open(line, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (1);
}

int	parse_textures(char *line, t_graphics *graphics)
{
	int		i;
	char	*refined;
	char	*path;

	i = 0;
	while (i < TEX_COUNT)
	{
		if (!ft_strncmp(line, graphics->flags[i], 2))
		{
			if (graphics->paths[i] != NULL) //duplicato
				return (-1);
			path = line + 2;
			if (*path != ' ' && *path != '\t')
				return (-1);
			if (*path == '\0')
				return (-1);
			refined = clean_line(path);
			if (!refined)
				return (-1);
			if (check_path(refined) > 0)
				// file con estensione valida e apribile
				graphics->paths[i] = refined;
			else
				return (free(refined), -1);
			return (1);
		}
		i++;
	}
	return (0);
}
