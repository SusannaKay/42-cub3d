/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:57:26 by skayed            #+#    #+#             */
/*   Updated: 2025/09/24 15:30:17 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->map)
	{
		i = 0;
		while (map->map[i])
		{
			free(map->map[i]);
			map->map[i] = NULL;
			i++;
		}
		free(map->map);
		map->map = NULL;
	}
	if (map->filename)
		free(map->filename);
	free(map);
}

void	free_graphics(t_graphics *graphics, void *mlx)
{
	if (graphics)
	{
		if (graphics->no)
			mlx_destroy_image(mlx, graphics->no);
		if (graphics->so)
			mlx_destroy_image(mlx, graphics->so);
		if (graphics->we)
			mlx_destroy_image(mlx, graphics->we);
		if (graphics->ea)
			mlx_destroy_image(mlx, graphics->ea);
	}
	free(graphics);
}

static void	free_all(t_game *game)
{
	if (game->map)
		free_map(game->map);
	if (game->graphics)
		free_graphics(game->mlx, game->map);
	if (game->mlx)
		mlx_loop_end(game->mlx);
	if (game->win)
	{
		mlx_destroy_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	free(game);
}

void	error_exit(char *msg, t_game *game)
{
	if (game)
		free_all(game);
	if (msg)
		ft_printf("Error:\n%s", msg);
	exit(EXIT_FAILURE);
}
