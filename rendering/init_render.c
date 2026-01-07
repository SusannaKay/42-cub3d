/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:05:41 by ebonacco          #+#    #+#             */
/*   Updated: 2026/01/07 13:49:11 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clear_frame_buffer(t_graphics *graphics)
{
	int		size;

	size = graphics->frame.line_len * HEIGHT;
	ft_bzero(graphics->frame.addr, size);
}

int	init_render(t_game *game)
{
	moves(game);
	rotations(game);
	clear_frame_buffer(game->graphics);
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->graphics->frame.img,
		0, 0);
	return (0);
}
