/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:00:00 by bpichyal          #+#    #+#             */
/*   Updated: 2026/06/08 23:21:35 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_frame(t_game *game)
{
	int	x;

	draw_background(game);
	x = 0;
	while (x < game->win_w)
	{
		raycast_column(game, x);
		x++;
	}
}
