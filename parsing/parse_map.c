/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbinti-m <dbinti-m@student.42kl.edu.my>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:00:00 by dbinti-m  #+#    #+#             */
/*   Updated: 2026/06/23 10:00:00 by dbinti-m  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int max_width(char **lines, int count)
{
	int max_w;
	int i;
	int len;
	max_w = 0;	i = 0;
	while (i < count)
	{
		len = (int)ft_strlen(lines[i]);
		if (len > max_w)
			max_w = len;
		i++;
	}
	return (max_w);
}

static int store_player(t_game *game, int x, int y, char dir)
{
	if (game->map.player_dir != 0)
		return (1);
	game->map.player_x = x;
	game->map.player_y = y;
	game->map.player_dir = dir;
	return (0);
}

static int pad_grid_row(t_game *game, char *line, int y, int w)
{
	int x;
	game->map.grid[y] = (char *)safe_malloc(w + 1);
	ft_memset(game->map.grid[y], ' ', w);
	game->map.grid[y][w] = '\0';
	ft_memcpy(game->map.grid[y], line, ft_strlen(line));
	x = 0;
	while (x < w)
	{
		if (ft_strchr("NSEW", game->map.grid[y][x]))
		{
			if (store_player(game, x, y, game->map.grid[y][x]) != 0)
				return (1);
			game->map.grid[y][x] = '0';
		}
		x++;
	}
	return (0);
}

int map_build(t_game *game, char **lines, int count)
{
	int y;
	int w;
	w = max_width(lines, count);
	game->map.width = w;
	game->map.height = count;
	game->map.grid = (char **)safe_malloc(sizeof(char *) * count);
	ft_bzero(game->map.grid, sizeof(char *) * count);
	y = 0;
	while (y < count)
	{
		if (pad_grid_row(game, lines[y], y, w) != 0)
			return (1);
		y++;
	}
	if (game->map.player_dir == 0)
		return (1);
	return (0);
}
