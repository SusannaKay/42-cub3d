/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonacco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:31:53 by ebonacco          #+#    #+#             */
/*   Updated: 2025/12/16 17:31:57 by ebonacco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned int	rgb_int(int rgb[3])
{
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void	put_pixel(t_img *frame, int x, int y, unsigned int color)
{
	char	*dst;
	int		bytes_pp;

	bytes_pp = frame->bit_pp / 8;
	dst = frame->addr + (y * frame->line_len) + (x * bytes_pp); // (y * frame->line_len) ti porta all’inizio della riga y, (x * bytes_pp) ti sposta nel pixel esatto. Finisce tutto in frame->addr!
	*(unsigned int *)dst = color;
}

unsigned int	get_pixel(t_img *img, int x, int y)
{
	char	*dst;
	int		bytes_pp;

	bytes_pp = img->bit_pp / 8;
	dst = img->addr + (y * img->line_len) + (x * bytes_pp);
	return (*(unsigned int *)dst);
}

void	draw_texture(t_game *game, t_wall *wall)
{
	double		step;
	double		tex_pos;
	unsigned int		color;
	int			y;
	int			tex_y;

	step = (double)wall->tex->h / wall->line_h;
	tex_pos = (wall->start - HEIGHT / 2 + wall->line_h / 2) * step;
	y = wall->start;
	while (y < wall->end)
	{
		tex_y = (int)tex_pos;
		tex_pos += step;
		color = get_pixel(wall->tex, wall->tex_x, tex_y);
		put_pixel(&game->graphics->frame, wall->x, y, color);
		y++;
	}
}

void	draw_world(t_game *game, int x)
{
	int		y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		put_pixel(&game->graphics->frame, x, y,
			rgb_int(game->graphics->ceiling));
		y++;
	}
	while (y < HEIGHT)
	{
		put_pixel(&game->graphics->frame, x, y,
			rgb_int(game->graphics->floor));
		y++;
	}
}

void	draw_hand(t_game *game, t_img *hand, int off_x, int off_y)
{
	int		x;
	int		y;
	unsigned int	color;

	y = 0;
	while (y < hand->h)
	{
		x = 0;
		while (x < hand->w)
		{
			if (x + off_x >= 0 && x + off_x < WIDTH && y + off_y >= 0
				&& y + off_y < HEIGHT)
			{
				color = get_pixel(hand, x, y);
				if (color != 0xFF00E2 && color != 0xFE00DF)
					put_pixel(&game->graphics->frame, x + off_x, y
						+ off_y, color);
			}
			x++;
		}
		y++;
	}
}
