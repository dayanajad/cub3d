/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:00:00 by bpichyal          #+#    #+#             */
/*   Updated: 2026/06/08 23:21:34 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_walkable(t_game *game, double x, double y)
{
	int	mx;
	int	my;

	mx = (int)x;
	my = (int)y;
	if (mx < 0 || my < 0 || mx >= game->map.width || my >= game->map.height)
		return (0);
	if (game->map.grid[my][mx] == '1'
		|| game->map.grid[my][mx] == ' ')
		return (0);
	return (1);
}

static void	move_forward(t_game *game, double dir_x, double dir_y)
{
	double	next_x;
	double	next_y;

	next_x = game->player.x + dir_x * game->move_speed;
	next_y = game->player.y + dir_y * game->move_speed;
	if (is_walkable(game, next_x, game->player.y))
		game->player.x = next_x;
	if (is_walkable(game, game->player.x, next_y))
		game->player.y = next_y;
}

void	handle_move(t_game *game)
{
	if (game->keys.w)
		move_forward(game, game->player.dir_x, game->player.dir_y);
	if (game->keys.s)
		move_forward(game, -game->player.dir_x, -game->player.dir_y);
	if (game->keys.a)
		move_forward(game, game->player.dir_y, -game->player.dir_x);
	if (game->keys.d)
		move_forward(game, -game->player.dir_y, game->player.dir_x);
	if (game->keys.left)
		rotate_player(&game->player, -game->rot_speed);
	if (game->keys.right)
		rotate_player(&game->player, game->rot_speed);
}
