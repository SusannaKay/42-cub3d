/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:22:27 by skayed            #+#    #+#             */
/*   Updated: 2025/10/16 15:06:16 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"
void init_graphics(t_graphics *graphics)
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
int	main(int argc, char **argv)
{
	t_game *game;

	if (argc == 2)
	{
		if (!ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
			return (error_exit("Map format should be *.cub", NULL), 1);
		// check file e mappa passando puntatori alle struct che servono
		// init grafico e init mlx
		game = ft_calloc(1, sizeof(t_game));
		if (!game)
			return(error_exit("perror", game), -1);
		game->graphics = ft_calloc(1, sizeof(t_graphics));
		if(!game->graphics)
			return(error_exit("perror", game), -1);
		init_graphics(game->graphics);
		game->map = ft_calloc(1, sizeof(t_map));
		if(!game->map)
			return(error_exit("perror", game), -1);
		game->map->filename = argv[1];
		check_cub(game);
		init_game(game);
		//mlx_loop(mlx->mlx);
		return (0);
	}
	else if (argc == 1)
		return (error_exit("you need a map .cub to play the game", NULL), -1);
	else
		return (error_exit("Wrong arguments number", NULL), -1);
	return (0);
}
