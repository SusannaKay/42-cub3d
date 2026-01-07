/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonacco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:05:41 by ebonacco          #+#    #+#             */
/*   Updated: 2025/11/11 10:05:45 by ebonacco         ###   ########.fr       */
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
		0, 0); // copia l’immagine off-screen nella window a ogn iiterazione
	return (0);
}
