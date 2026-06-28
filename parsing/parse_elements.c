/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbinti-m <dbinti-m@student.42kl.edu.my>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:00:00 by dbinti-m  #+#    #+#             */
/*   Updated: 2026/06/23 10:00:00 by dbinti-m  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int is_space(char c) { return (c == ' ' || c == '\t'); }

static int skip_spaces(char *s, int i)
{
	while (s[i] && is_space(s[i]))
		i++;
	return (i);
}

int parse_elements(t_game *game, char *line)
{
	int i;
	i = skip_spaces(line, 0);
	if (line[i] == '\0')
		return (0);
	if (line[i] == 'N' && line[i + 1] == 'O' && is_space(line[i + 2]))
		return (parse_texture_line(&game->tex[TEX_N].path, line + i + 2));
	if (line[i] == 'S' && line[i + 1] == 'O' && is_space(line[i + 2]))
		return (parse_texture_line(&game->tex[TEX_S].path, line + i + 2));
	if (line[i] == 'W' && line[i + 1] == 'E' && is_space(line[i + 2]))
		return (parse_texture_line(&game->tex[TEX_W].path, line + i + 2));
	if (line[i] == 'E' && line[i + 1] == 'A' && is_space(line[i + 2]))
		return (parse_texture_line(&game->tex[TEX_E].path, line + i + 2));
	if (line[i] == 'F' && is_space(line[i + 1]))
		return (parse_color_line(&game->floor, line + i + 1));
	if (line[i] == 'C' && is_space(line[i + 1]))
		return (parse_color_line(&game->ceil, line + i + 1));
	return (1);
}

int parse_texture_line(char **path, char *line)
{
	char *trim;
	if (*path)
		return (1);
	trim = ft_strtrim(line, " \t");
	if (!trim || !*trim)
	{
		free(trim);
		return (1);
	}
	*path = trim;
	return (0);
}
