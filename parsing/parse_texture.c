/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:37:25 by skayed            #+#    #+#             */
/*   Updated: 2025/10/17 14:41:34 by skayed           ###   ########.fr       */
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
			if (check_path(refined) > 0) // file con estensione valida e apribile
				graphics->paths[i] = refined;
			else
				return (free(refined), -1);
			return (1);
		}
		i++;
	}
	return (0);
}
