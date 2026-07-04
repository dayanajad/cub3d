/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:00:00 by bpichyal          #+#    #+#             */
/*   Updated: 2026/06/08 23:21:27 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_row(t_game *game, int y, int color)
{
	int	x;

	x = 0;
	while (x < game->win_w)
	{
		img_put_pixel(&game->frame, x, y, color);
		x++;
	}
}

void	draw_background(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->win_h / 2)
	{
		fill_row(game, y, game->ceil.value);
		y++;
	}
	while (y < game->win_h)
	{
		fill_row(game, y, game->floor.value);
		y++;
	}
}
