/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbinti-m <dbinti-m@student.42kl.edu.my>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:00:00 by dbinti-m  #+#    #+#             */
/*   Updated: 2026/06/23 10:00:00 by dbinti-m  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parse_cub(t_game *game, char *path)
{
	int fd;
	char *line;

	(void)game;
	if (!has_cub_ext(path))
		return (1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		ft_printf("line: %s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
