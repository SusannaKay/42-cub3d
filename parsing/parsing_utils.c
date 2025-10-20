/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:44:32 by skayed            #+#    #+#             */
/*   Updated: 2025/10/20 17:02:03 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*check_line(char *line)
{
	if (*line == '\n')
		return (NULL);
	while (*line == ' ')
		line++;
	return (line);
}

char	*clean_line(char *s)
{
	int		start;
	int		end;
	char	*res;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] == ' ' || s[start] == '\t')
		start++;
	end = ft_strlen(s);
	while (end > start && (s[end - 1] == ' ' || s[end - 1] == '\t'))
		end--;
	res = ft_substr(s, start, end - start);
	if (!res)
		return (NULL);
	return (res);
}

void	ft_close(char *msg, char *line, int fd, t_game *game)
{
	free(line);
	close(fd);
	error_exit(msg, game);
}

int	map_line(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '\0')
		return (0);
	if (line[i] == '1' || line[i] == '0' || line[i] == 'N' || line[i] == 'S'
		|| line[i] == 'E' || line[i] == 'W')
	{
		i++;
		if (line[i] == '0' || line[i] == '1')
		{
			if (game->map->in_map == 0)
				game->map->in_map = 1;
			printf("Line is a valid map line: %s\n", line);
			return (1);
		}
	}
	printf("Line is not a valid map line: %s\n", line);
	return (0);
}

int	check_gstruct(t_graphics *graphics)
// controlla se manca qualche info grafica
{
	int i;

	i = 0;
	while (i < TEX_COUNT)
	{
		if (!graphics->paths[i] || graphics->paths[i] == NULL)
			return (-1);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (graphics->floor[i] == -1 || graphics->ceiling[i] == -1)
			return (-1);
		i++;
	}
	return (1);
}
