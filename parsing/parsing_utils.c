/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:44:32 by skayed            #+#    #+#             */
/*   Updated: 2025/10/15 12:52:21 by skayed           ###   ########.fr       */
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

int	check_path(char *line)// controlla se l'estensione e' giusta e se e' possibile aprirle il file grafico
{
	int len;
	int fd;

	len = ft_strlen(line) - 4;
	if (!ft_strncmp(line + len, ".xpm", 4))
	{
		fd = open(line, O_RDONLY);
		if (fd < 0)
			return (-1);
		close(fd);
	}
	return (0);
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
