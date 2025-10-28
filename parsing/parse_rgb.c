/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:52:40 by skayed            #+#    #+#             */
/*   Updated: 2025/10/28 15:30:12 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_rgb(char *line, t_game *game)
{
	char	**matrix;
	int		i;
	int		num;
	int		*rgb;
	char *cleaned;

	if (*line == 'F')
		rgb = game->graphics->floor;
	else if (*line == 'C')
		rgb = game->graphics->ceiling;
	else
		return (-1);
	line++;
	while (line && (*line == ' ' || *line == '\t'))
		line++; // arriva al primo numero
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
		{
			free_matrix(matrix);
			return (-1);
		}
		free(matrix[i]);
		matrix[i] = cleaned;
		//free(cleaned);
		num = ft_atoi(matrix[i]);
		if (num < 0 || num > 255)
		{
			free_matrix(matrix);
			return (-1);
		}
		if (rgb[i] != -1) // duplicato
		{
			free_matrix(matrix);
			return (-1);
		}
		rgb[i] = num;
		i++;
	}
	if (i != 3 || matrix[i] != NULL) // check se ci sono piu di 3 numeri
	{
		free_matrix(matrix);
		return (-1);
	}
	free_matrix(matrix);
	return (0);
}
