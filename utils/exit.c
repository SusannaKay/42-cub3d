/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:57:26 by skayed            #+#    #+#             */
/*   Updated: 2025/10/28 14:43:07 by skayed           ###   ########.fr       */
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
	free(map);
}

void	free_graphics(t_graphics *graphics)
{
	// int	i;

	// i = 0;
	// if (graphics)
	// {
	// 	// while (i < TEX_COUNT)
	// 	// {
	// 	// 	// if (graphics->wall_img[i])
	// 	// 	// 	mlx_destroy_image(mlx, graphics->wall_img[i]);
	// 	// 	// if (graphics->flags[i])
	// 	// 	// 	free((void *)graphics->flags[i]);
	// 	// 	// if (graphics->paths[i])
	// 	// 	// 	free(graphics->paths[i]);
	// 	// 	i++;
	// 	// }
	// }
	free(graphics);
}

static void	free_all(t_game *game)
{
	if (game->map)
		free_map(game->map);
	if (game->graphics)
		free_graphics(game->graphics);
	if (game->mlx)
		mlx_loop_end(game->mlx);
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
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
