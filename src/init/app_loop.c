/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:00:00 by bpichyal          #+#    #+#             */
/*   Updated: 2026/06/08 23:21:37 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_game *game)
{
	double	delta;
	long	now;

	now = time_ms();
	delta = (double)(now - game->last_time) / 1000.0;
	if (delta < 0.0)
		delta = 0.0;
	if (delta > 0.05)
		delta = 0.05;
	game->move_speed = delta * 3.0;
	game->rot_speed = delta * 2.0;
	game->last_time = now;
	handle_move(game);
	render_frame(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
	return (0);
}
