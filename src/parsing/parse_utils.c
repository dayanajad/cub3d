/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbinti-m <dbinti-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:00:00 by dbinti-m          #+#    #+#             */
/*   Updated: 2026/06/10 15:30:06 by dbinti-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*strip_newline(char *line)
{
	size_t	len;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\r')
		line[len - 1] = '\0';
	return (line);
}

int	is_map_line(char *line)
{
	int	i;
	int	has_tile;

	i = 0;
	has_tile = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (ft_strchr(" 01NSEW", line[i]))
		{
			if (line[i] != ' ')
				has_tile = 1;
		}
		else
			return (0);
		i++;
	}
	return (has_tile);
}

void	map_store_line(char ***lines, int *count, char *line)
{
	char	**new_lines;
	int		i;

	new_lines = (char **)safe_malloc(sizeof(char *) * (*count + 1));
	i = 0;
	while (i < *count)
	{
		new_lines[i] = (*lines)[i];
		i++;
	}
	new_lines[*count] = ft_strdup(line);
	if (!new_lines[*count])
	{
		free_lines(new_lines, *count);
		cub_error("Malloc failed");
	}
	free(*lines);
	*lines = new_lines;
	(*count)++;
}

int	has_cub_ext(char *path)
{
	size_t	len;

	if (!path)
		return (0);
	len = ft_strlen(path);
	if (len < 5)
		return (0);
	return (ft_strncmp(path + len - 4, ".cub", 4) == 0);
}

int	is_blank_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (line[i] == '\0');
}
