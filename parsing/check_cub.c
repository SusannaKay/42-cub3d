/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:25:17 by skayed            #+#    #+#             */
/*   Updated: 2025/09/22 15:56:32 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_cub(char *filename)
{
	int fd;
	char *line;
	char *pos;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
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