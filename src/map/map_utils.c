/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:00:00 by bpichyal          #+#    #+#             */
/*   Updated: 2026/06/08 23:21:32 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_dir_n(t_player *p)
{
	p->dir_x = 0;
	p->dir_y = -1;
	p->plane_x = FOV;
	p->plane_y = 0;
}

static void	set_dir_s(t_player *p)
{
	p->dir_x = 0;
	p->dir_y = 1;
	p->plane_x = -FOV;
	p->plane_y = 0;
}

static void	set_dir_e(t_player *p)
{
	p->dir_x = 1;
	p->dir_y = 0;
	p->plane_x = 0;
	p->plane_y = FOV;
}

static void	set_dir_w(t_player *p)
{
	p->dir_x = -1;
	p->dir_y = 0;
	p->plane_x = 0;
	p->plane_y = -FOV;
}

void	init_player(t_game *game)
{
	game->player.x = game->map.player_x + 0.5;
	game->player.y = game->map.player_y + 0.5;
	if (game->map.player_dir == 'N')
		set_dir_n(&game->player);
	else if (game->map.player_dir == 'S')
		set_dir_s(&game->player);
	else if (game->map.player_dir == 'E')
		set_dir_e(&game->player);
	else if (game->map.player_dir == 'W')
		set_dir_w(&game->player);
}
