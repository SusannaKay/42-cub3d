/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:52:40 by skayed            #+#    #+#             */
/*   Updated: 2026/01/19 10:14:51 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	*assign_fc(char c, t_game *game)
{
	if (c == 'F')
		return (game->graphics->floor);
	if (c == 'C')
		return (game->graphics->ceiling);
	return (NULL);
}

static int	line_isdigit(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (-1);
		i++;
	}
	return (0);
}

static int	fill_rgb(char **matrix, int *rgb)
{
	int		i;
	int		num;
	char	*cleaned;

	i = 0;
	while (matrix[i] && i < 3)
	{
		cleaned = clean_line(matrix[i]);
		if (!cleaned)
			return (-1);
		free(matrix[i]);
		matrix[i] = cleaned;
		if (line_isdigit(matrix[i]) < 0)
			return (-1);
		num = ft_atoi(matrix[i]);
		if (num < 0 || num > 255)
			return (-1);
		if (rgb[i] != -1)
			return (-1);
		rgb[i] = num;
		i++;
	}
	if (i != 3 || matrix[i] != NULL)
		return (-1);
	return (0);
}

int	parse_rgb(char *line, t_game *game)
{
	char	**matrix;
	int		*rgb;

	rgb = assign_fc(*line, game);
	if (!rgb)
		return (-1);
	line++;
	while (line && (*line == ' ' || *line == '\t'))
		line++;
	if (*line == '\0')
		return (-1);
	matrix = ft_split(line, ',');
	if (!matrix)
		return (-1);
	if (fill_rgb(matrix, rgb) != 0)
		return (free_matrix(matrix), -1);
	free_matrix(matrix);
	return (0);
}
