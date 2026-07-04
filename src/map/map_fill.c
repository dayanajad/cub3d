/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:00:00 by bpichyal          #+#    #+#             */
/*   Updated: 2026/06/08 23:37:40 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	cell_invalid(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map.width || y >= game->map.height)
		return (1);
	if (game->map.grid[y][x] == ' ')
		return (1);
	if ((x == 0 || y == 0 || x == game->map.width - 1
			|| y == game->map.height - 1) && game->map.grid[y][x] != '1')
		return (1);
	return (0);
}

static int	push_neighbors(t_game *game, t_fill *f, int x, int y)
{
	static const int	dx[4] = {1, -1, 0, 0};
	static const int	dy[4] = {0, 0, 1, -1};
	int					i;
	int					nx;
	int					ny;

	i = 0;
	while (i < 4)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (cell_invalid(game, nx, ny))
			return (1);
		if (!f->vis[ny * game->map.width + nx]
			&& game->map.grid[ny][nx] != '1')
		{
			f->vis[ny * game->map.width + nx] = 1;
			f->sx[f->top] = nx;
			f->sy[f->top] = ny;
			f->top++;
		}
		i++;
	}
	return (0);
}

static int	process_cell(t_game *game, t_fill *f, int x, int y)
{
	if (cell_invalid(game, x, y))
		return (1);
	if (game->map.grid[y][x] != '1')
		return (push_neighbors(game, f, x, y));
	return (0);
}

static int	flood_fill(t_game *game, t_fill *f)
{
	int	x;
	int	y;
	int	idx;

	f->top = 0;
	f->sx[f->top] = game->map.player_x;
	f->sy[f->top] = game->map.player_y;
	idx = game->map.player_y * game->map.width + game->map.player_x;
	f->vis[idx] = 1;
	f->top++;
	while (f->top > 0)
	{
		f->top--;
		x = f->sx[f->top];
		y = f->sy[f->top];
		if (process_cell(game, f, x, y) != 0)
			return (1);
	}
	return (0);
}

int	map_is_closed(t_game *game)
{
	t_fill	f;
	int		open;

	f.vis = (char *)safe_malloc(game->map.width * game->map.height);
	ft_memset(f.vis, 0, game->map.width * game->map.height);
	f.sx = (int *)safe_malloc(sizeof(int) * game->map.width * game->map.height);
	f.sy = (int *)safe_malloc(sizeof(int) * game->map.width * game->map.height);
	open = flood_fill(game, &f);
	free(f.vis);
	free(f.sx);
	free(f.sy);
	return (open);
}
