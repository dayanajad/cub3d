/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbinti-m <dbinti-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:00:00 by dbinti-m          #+#    #+#             */
/*   Updated: 2026/06/10 15:28:12 by dbinti-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

static int	skip_spaces(char *s, int i)
{
	while (s[i] && is_space(s[i]))
		i++;
	return (i);
}

static int	parse_number(char *s, int *i, int *out)
{
	int	val;
	int	digits;

	val = 0;
	digits = 0;
	if (!ft_isdigit(s[*i]))
		return (1);
	while (ft_isdigit(s[*i]))
	{
		if (digits >= 3)
			return (1);
		val = val * 10 + (s[*i] - '0');
		digits++;
		(*i)++;
	}
	if (val > 255)
		return (1);
	*out = val;
	return (0);
}

static int	parse_rgb(char *line, int *r, int *g, int *b)
{
	int	i;

	i = skip_spaces(line, 0);
	if (parse_number(line, &i, r) != 0)
		return (1);
	i = skip_spaces(line, i);
	if (line[i++] != ',')
		return (1);
	i = skip_spaces(line, i);
	if (parse_number(line, &i, g) != 0)
		return (1);
	i = skip_spaces(line, i);
	if (line[i++] != ',')
		return (1);
	i = skip_spaces(line, i);
	if (parse_number(line, &i, b) != 0)
		return (1);
	i = skip_spaces(line, i);
	return (line[i] != '\0');
}

int	parse_color_line(t_color *color, char *line)
{
	int	r;
	int	g;
	int	b;

	if (color->set)
		return (1);
	if (parse_rgb(line, &r, &g, &b) != 0)
		return (1);
	color->value = color_rgb(r, g, b);
	color->set = 1;
	return (0);
}
