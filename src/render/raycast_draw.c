/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:00:00 by bpichyal          #+#    #+#             */
/*   Updated: 2026/06/08 23:21:38 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	calc_wall_dist(t_game *game, t_ray *ray)
{
	double	dist;

	if (ray->side == 0)
		dist = (ray->map_x - game->player.x + (1 - ray->step_x) / 2.0)
			/ ray->raydir_x;
	else
		dist = (ray->map_y - game->player.y + (1 - ray->step_y) / 2.0)
			/ ray->raydir_y;
	ray->perp_wall_dist = dist;
	if (dist <= 0.0001)
		return (1);
	return (0);
}

static void	calc_draw_limits(t_game *game, double dist, t_draw *d)
{
	d->line_h = (int)(game->win_h / dist);
	d->draw_start = -d->line_h / 2 + game->win_h / 2;
	d->draw_end = d->line_h / 2 + game->win_h / 2;
	if (d->draw_start < 0)
		d->draw_start = 0;
	if (d->draw_end >= game->win_h)
		d->draw_end = game->win_h - 1;
}

static void	prepare_draw(t_game *game, t_ray *ray, t_draw *d)
{
	double	wall_x;

	d->tex = &game->tex[select_texture(ray)].img;
	if (ray->side == 0)
		wall_x = game->player.y + ray->perp_wall_dist * ray->raydir_y;
	else
		wall_x = game->player.x + ray->perp_wall_dist * ray->raydir_x;
	wall_x -= floor(wall_x);
	d->tex_x = (int)(wall_x * (double)d->tex->w);
	if (ray->side == 0 && ray->raydir_x > 0)
		d->tex_x = d->tex->w - d->tex_x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		d->tex_x = d->tex->w - d->tex_x - 1;
}

static void	draw_tex_column(t_game *game, t_draw *d, int x)
{
	double	step;
	double	tex_pos;
	int		y;
	int		color;

	step = 1.0 * d->tex->h / d->line_h;
	tex_pos = (d->draw_start - game->win_h / 2 + d->line_h / 2) * step;
	y = d->draw_start;
	while (y <= d->draw_end)
	{
		color = img_get_pixel(d->tex, d->tex_x, (int)tex_pos);
		img_put_pixel(&game->frame, x, y, color);
		tex_pos += step;
		y++;
	}
}

void	raycast_draw_column(t_game *game, t_ray *ray, int x)
{
	t_draw	d;

	if (calc_wall_dist(game, ray) != 0)
		return ;
	calc_draw_limits(game, ray->perp_wall_dist, &d);
	if (d.line_h <= 0)
		return ;
	prepare_draw(game, ray, &d);
	draw_tex_column(game, &d, x);
}
