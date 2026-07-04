/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:00:00 by bpichyal          #+#    #+#             */
/*   Updated: 2026/06/08 23:37:39 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	start_game(t_game *game)
{
	game->last_time = time_ms();
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
}

static int	init_all(t_game *game, char **argv)
{
	if (parse_cub(game, argv[1]) != 0)
	{
		ft_error("Invalid map file");
		free_game(game);
		return (1);
	}
	if (init_mlx(game) != 0)
	{
		ft_error("Failed to initialized window");
		free_game(game);
		return (1);
	}
	if (load_textures(game) != 0)
	{
		ft_error("Failed to load textures");
		free_game(game);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_error("Usage: ./cub3D <map.cub>");
		return (1);
	}
	ft_memset(&game, 0, sizeof(t_game));
	init_game(&game);
	if (init_all(&game, argv) != 0)
		return (1);
	init_player(&game);
	start_game(&game);
	return (0);
}
