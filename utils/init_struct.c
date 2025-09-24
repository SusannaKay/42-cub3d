/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:23:31 by skayed            #+#    #+#             */
/*   Updated: 2025/09/24 17:08:32 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


t_game	*init_game(t_game *game)
{
	t_graphics *graphics;

	graphics = ft_calloc(1, sizeof(t_graphics));
	if (!graphics)
		return (error_exit(perror, NULL), NULL);
	game->graphics = graphics;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 300, 300, "The Maze");
	return (game);
}