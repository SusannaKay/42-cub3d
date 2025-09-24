/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:22:27 by skayed            #+#    #+#             */
/*   Updated: 2025/09/23 17:00:15 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game *game;
	t_map	*map;

	if (argc == 2)
	{
		if (!ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
			return(ft_printf("Error\nMap format should be *.cub"), 1);
		// inizializza strutture mappa
		// check file e mappa passando puntatori alle struct che servono
		// init grafico e init mlx
		map = init_map(map);
		map->filename = argv[1];
		
		init_game(game);
		mlx_loop(mlx->mlx);
		return (0);
	}
	ft_printf("Error:\n you need a map .cub to play the game");
	return (-1);
}