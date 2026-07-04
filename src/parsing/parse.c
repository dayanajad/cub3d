/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbinti-m <dbinti-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:00:00 by dbinti-m          #+#    #+#             */
/*   Updated: 2026/06/10 15:27:34 by dbinti-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_elements(t_game *game)
{
	if (!game->tex[TEX_N].path || !game->tex[TEX_S].path
		|| !game->tex[TEX_W].path || !game->tex[TEX_E].path)
		return (1);
	if (!game->floor.set || !game->ceil.set)
		return (1);
	return (0);
}

static int	parse_line(t_game *game, t_parse *p, char *line)
{
	strip_newline(line);
	if (!p->in_map && is_blank_line(line))
		return (0);
	if (!p->in_map && is_map_line(line))
	{
		p->in_map = 1;
		map_store_line(&p->map_lines, &p->map_count, line);
		return (0);
	}
	if (p->in_map)
	{
		if (is_blank_line(line))
		{
			p->map_done = 1;
			return (0);
		}
		if (p->map_done || !is_map_line(line))
			return (1);
		map_store_line(&p->map_lines, &p->map_count, line);
		return (0);
	}
	if (parse_elements(game, line) != 0)
		return (1);
	return (0);
}

static int	finish_parse(t_game *game, char **map_lines, int map_count)
{
	if (map_count == 0 || check_elements(game) != 0)
		return (1);
	if (map_build(game, map_lines, map_count) != 0)
		return (1);
	if (map_validate(game) != 0)
		return (1);
	return (0);
}

static int	parse_fd(t_game *game, int fd, t_parse *p)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (parse_line(game, p, line) != 0)
		{
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	parse_cub(t_game *game, char *path)
{
	int		fd;
	t_parse	p;

	if (!has_cub_ext(path))
		return (1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	ft_memset(&p, 0, sizeof(p));
	if (parse_fd(game, fd, &p) != 0)
	{
		free_lines(p.map_lines, p.map_count);
		close(fd);
		return (1);
	}
	close(fd);
	if (finish_parse(game, p.map_lines, p.map_count) != 0)
	{
		free_lines(p.map_lines, p.map_count);
		return (1);
	}
	free_lines(p.map_lines, p.map_count);
	return (0);
}
