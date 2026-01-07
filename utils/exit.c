/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:57:26 by skayed            #+#    #+#             */
/*   Updated: 2026/01/07 15:08:06 by skayed           ###   ########.fr       */
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
	printf("free_all: game->map = %p\n", map);
	free(map);
}

void	free_graphics(t_graphics *graphics, void *mlx)
{
	int	i;

	if (!graphics)
		return ;
	i = 0;
	while (i < TEX_COUNT)
	{
		if (graphics->paths[i])
		{
			free(graphics->paths[i]);
			graphics->paths[i] = NULL;
		}
		if (graphics->wall_img[i].img)
			mlx_destroy_image(mlx, graphics->wall_img[i].img);
		i++;
	}
	if (graphics->frame.img)
		mlx_destroy_image(mlx, graphics->frame.img);
	if (graphics->hand_r.img)
		mlx_destroy_image(mlx, graphics->hand_r.img);
	if (graphics->hand_l.img)
		mlx_destroy_image(mlx, graphics->hand_l.img);
	free(graphics);
}

static void	free_all(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
	{
		free_map(game->map);
		game->map = NULL;
	}
	if (game->graphics)
	{
		free_graphics(game->graphics, game->mlx);
		game->graphics = NULL;
	}
	if (game->keys)
	{
		free(game->keys);
		game->keys = NULL;
	}
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		mlx_loop_end(game->mlx);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	free(game);
}

int	error_exit(char *msg, t_game *game)
{
	if (game)
		free_all(game);
	if (msg)
		ft_printf("Error:\n%s", msg);
	exit(EXIT_FAILURE);
	return (0);
}

int	exit_destroy(t_game *game)
{
	if (game)
		free_all(game);
	exit(0);
	return (0);
}

void	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
}
