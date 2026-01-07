/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:44:32 by skayed            #+#    #+#             */
/*   Updated: 2026/01/07 15:30:40 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	line_len(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j] == ' ' || game->map->map[i][j] == '\t')
			j++;
		if (game->map->map[i][j] == '1')
			break ;
		i++;
	}
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j] && game->map->map[i][j] != '\n'
				&& game->map->map[i][j] != '\t' && game->map->map[i][j] != ' ')
			j++;
		if (j > game->graphics->line_len)
			game->graphics->line_len = j;
		i++;
	}
}

int	map_line(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if ((line[i] == '\0' || line[i] == '\n') && game->map->in_map == 1)
		return (-1);
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
			return (1);
		}
	}
	return (0);
}

int	check_gstruct(t_graphics *graphics)
{
	int		i;

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
