/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:00:00 by bpichyal          #+#    #+#             */
/*   Updated: 2026/06/08 23:21:25 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		close_window(game);
	if (key == KEY_W)
		game->keys.w = 1;
	else if (key == KEY_S)
		game->keys.s = 1;
	else if (key == KEY_A)
		game->keys.a = 1;
	else if (key == KEY_D)
		game->keys.d = 1;
	else if (key == KEY_LEFT)
		game->keys.left = 1;
	else if (key == KEY_RIGHT)
		game->keys.right = 1;
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == KEY_W)
		game->keys.w = 0;
	else if (key == KEY_S)
		game->keys.s = 0;
	else if (key == KEY_A)
		game->keys.a = 0;
	else if (key == KEY_D)
		game->keys.d = 0;
	else if (key == KEY_LEFT)
		game->keys.left = 0;
	else if (key == KEY_RIGHT)
		game->keys.right = 0;
	return (0);
}
