/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 23:28:55 by bpichyal          #+#    #+#             */
/*   Updated: 2026/06/08 23:38:12 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *game)
{
	game->win_w = WIN_W;
	game->win_h = WIN_H;
	game->move_speed = 0.0;
	game->rot_speed = 0.0;
	game->floor.set = 0;
	game->ceil.set = 0;
}

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->win = mlx_new_window(game->mlx, game->win_w, game->win_h, "cub3D");
	if (!game->win)
		return (1);
	game->frame.img = mlx_new_image(game->mlx, game->win_w, game->win_h);
	if (!game->frame.img)
		return (1);
	game->frame.addr = mlx_get_data_addr(game->frame.img, &game->frame.bpp,
			&game->frame.line_len, &game->frame.endian);
	game->frame.w = game->win_w;
	game->frame.h = game->win_h;
	return (0);
}
