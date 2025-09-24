/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:22:27 by skayed            #+#    #+#             */
/*   Updated: 2025/09/24 15:12:44 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game *game;
	t_map *map;

	if (argc == 2)
	{
		if (!ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
			return (error_exit("Map format should be *.cub", game), 1);
		// inizializza strutture mappa
		// check file e mappa passando puntatori alle struct che servono
		// init grafico e init mlx
		map = init_map(map);
		map->filename = argv[1];
		init_game(game);
		game->map = map;
		mlx_loop(mlx->mlx);
		return (0);
	}
	else if (argc == 1)
		return (error_exit("you need a map .cub to play the game", game));
	else
		return (error_exit("Wrong arguments number", game));
	return (0);
}