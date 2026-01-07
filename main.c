/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:22:27 by skayed            #+#    #+#             */
/*   Updated: 2026/01/07 12:53:30 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	key_down(int keysym, t_game *game)
{
	if (keysym == ESC)
		exit_destroy(game); // EU attenzione questa chiamata e stata cambiata vedi dopo
	if (keysym == W)
		game->keys->w = 1;
	if (keysym == S)
		game->keys->s = 1;
	if (keysym == A)
		game->keys->a = 1;
	if (keysym == D)
		game->keys->d = 1;
	if (keysym == LEFT)
		game->keys->left = 1;
	if (keysym == RIGHT)
		game->keys->right = 1;
	return (0);
}

int	key_up(int keysym, t_game *game)
{
	if (keysym == W)
		game->keys->w = 0;
	if (keysym == S)
		game->keys->s = 0;
	if (keysym == A)
		game->keys->a = 0;
	if (keysym == D)
		game->keys->d = 0;
	if (keysym == LEFT)
		game->keys->left = 0;
	if (keysym == RIGHT)
		game->keys->right = 0;
	return (0);
}

void	player_dir(t_game *game)
{
	if (game->map->p_dir == 'N')
	{
		game->map->dir_x = 0;
		game->map->dir_y = -1;
	}
	else if (game->map->p_dir == 'S')
	{
		game->map->dir_x = 0;
		game->map->dir_y = 1;
	}
	else if (game->map->p_dir == 'E')
	{
		game->map->dir_x = 1;
		game->map->dir_y = 0;
	}
	else if (game->map->p_dir == 'W')
	{
		game->map->dir_x = -1;
		game->map->dir_y = 0;
	}
}

static void	create_loop(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, key_down, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, key_up, game);
	mlx_hook(game->win, 17, 0L, exit_destroy, game);
	mlx_loop_hook(game->mlx, init_render, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		if (!ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
			return (error_exit("Map format should be *.cub", NULL), -1);
		game = ft_calloc(1, sizeof(t_game));
		if (!game)
			return (error_exit("Malloc failed", game), -1);
		game = init_game(&game);
		game->map->filename = argv[1];
		check_cub(game);
		verify_map(game);
		init_mlx(game);
		player_dir(game);
		create_loop(game);
		return (0);
	}
	else if (argc == 1)
		return (error_exit("you need a map .cub to play the game", NULL), -1);
	else
		return (error_exit("Wrong arguments number", NULL), -1);
	return (0);
}
