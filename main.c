/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:22:27 by skayed            #+#    #+#             */
/*   Updated: 2025/11/03 12:25:28 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static int	key_down(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		error_exit("Quit program by user", game);
	// else
	// 	move_player(keysym, game);
	return (0);
}

static void	create_loop(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, key_down, game);
	mlx_hook(game->win, 17, 0L, error_exit, game);
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
		game = init_game(&game);
		game->map->filename = argv[1];
		check_cub(game);
		verify_map(game);
		create_loop(game);
		return (0);
	}
	else if (argc == 1)
		return (error_exit("you need a map .cub to play the game", NULL), -1);
	else
		return (error_exit("Wrong arguments number", NULL), -1);
	return (0);
}
