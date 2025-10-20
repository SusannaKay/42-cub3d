/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:22:27 by skayed            #+#    #+#             */
/*   Updated: 2025/10/20 18:32:19 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	init_graphics(t_graphics *graphics)
{
	graphics->flags[TEX_NO] = "NO";
	graphics->flags[TEX_SO] = "SO";
	graphics->flags[TEX_WE] = "WE";
	graphics->flags[TEX_EA] = "EA";
	graphics->floor[0] = -1;
	graphics->floor[1] = -1;
	graphics->floor[2] = -1;
	graphics->ceiling[0] = -1;
	graphics->ceiling[1] = -1;
	graphics->ceiling[2] = -1;
}

void print_map(char **map)
{
	int i = 0;
	printf("Current map state:\n");
	while (map && map[i])
	{
		printf("Row %d: %s\n", i, map[i]);
		i++;
	}
}
int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		if (!ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
			return (error_exit("Map format should be *.cub", NULL), -1);
		printf("Starting game with map: %s\n", argv[1]);
		game = ft_calloc(1, sizeof(t_game));
		game = init_game(&game);
		game->map->filename = argv[1];
		printf("filename : %s\n", game->map->filename);
		printf("check cub\n");
		check_cub(game);
		print_map(game->map->map);
		//mlx_loop(mlx->mlx);
		return (0);
	}
	else if (argc == 1)
		return (error_exit("you need a map .cub to play the game", NULL), -1);
	else
		return (error_exit("Wrong arguments number", NULL), -1);
	return (0);
}
