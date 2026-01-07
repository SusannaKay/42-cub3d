/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:52:40 by skayed            #+#    #+#             */
/*   Updated: 2026/01/07 16:15:27 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int assign_fc(char c)
{
	if (c == 'F')
		rgb = game->graphics->floor;
	else if (c == 'C')
		rgb = game->graphics->ceiling;
	else
		return (-1);
	return (0);
}

static int 
int	parse_rgb(char *line, t_game *game)
{
	char	**matrix;
	int		i;
	int		num;
	int		*rgb;
	char	*cleaned;

	if (assign_fc(*line) < 0)
		return (-1);
	line++;
	while (line && (*line == ' ' || *line == '\t'))
		line++;
	if (*line == '\0')
		return (-1);
	matrix = ft_split(line, ',');
	if (!matrix)
		return (-1);
	i = 0;
	while (matrix[i] && i < 3)
	{
		cleaned = clean_line(matrix[i]);
		if (!cleaned)
			return (free_matrix(matrix), -1);
		free(matrix[i]);
		matrix[i] = cleaned;
		num = ft_atoi(matrix[i]);
		if (num < 0 || num > 255)
			return (free_matrix(matrix), -1);
		if (rgb[i] != -1)
			return (free_matrix(matrix), -1);
		rgb[i] = num;
		i++;
	}
	if (i != 3 || matrix[i] != NULL)
		return (free_matrix(matrix), -1);
	free_matrix(matrix);
	return (0);
}
