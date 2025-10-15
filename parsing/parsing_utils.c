/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:44:32 by skayed            #+#    #+#             */
/*   Updated: 2025/10/15 15:18:49 by skayed           ###   ########.fr       */
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
	int start;
	int end;
	char *res;

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

void ft_close(char *msg, , char *line, int fd, t_game *game)
{
	free(line);
	close(fd);
	error_exit(msg, game);
}

void map_line(char *line, t_game *game)
{
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	if (*line == '\0')
		return (0);
	if (*line == '1' || *line == '0' || *line == 'N' || *line == 'S'
		|| *line == 'E' || *line == 'W')
	{
		game->map->in_map = 1;
		return (1);
	}
	return(0);
}
