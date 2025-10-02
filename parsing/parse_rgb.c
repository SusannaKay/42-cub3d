/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:52:40 by skayed            #+#    #+#             */
/*   Updated: 2025/10/02 15:10:20 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_rgb(char *line, t_game *game)
{
	char	**matrix;
	int		i;
	int		num;

	if (!ft_strncmp(line, 'F', 1) || !ft_strncmp(line, 'C', 1))
	{
		line++;
		if (*line != ' ' && *line != '\t')
			return (-1);
		if (*line == '\0')
			return (-1);
		while ((*line == ' ' || *line == '\t') && *line)
			line++; // primo numero
		matrix = ft_split(line, ',');
		if (!matrix)
			return (-1);
		while (matrix[i])
		{
			clean_line(matrix[i]);
			num = ft_atoi(matrix[i]);
			if (num >= 0 && num <= 255)
			{
				if (!game->graphics->floor[i])
					game->graphics->floor[i] = num;
				else
				return()
			}
			i++;
		}
	}
}
