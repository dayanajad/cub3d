/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:00:00 by bpichyal          #+#    #+#             */
/*   Updated: 2026/06/08 23:24:45 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
# include "../libft/libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"

# define WIN_W 1280
# define WIN_H 720
# define FOV 0.66

# define TEX_N 0
# define TEX_S 1
# define TEX_W 2
# define TEX_E 3

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_tex
{
	char	*path;
	t_img	img;
}	t_tex;

typedef struct s_color
{
	int		value;
	int		set;
}	t_color;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	char	player_dir;
}	t_map;

typedef struct s_parse
{
	int		in_map;
	int		map_done;
	char	**map_lines;
	int		map_count;
}	t_parse;

typedef struct s_fill
{
	char	*vis;
	int		*sx;
	int		*sy;
	int		top;
}	t_fill;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_ray
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_ray;

typedef struct s_draw
{
	int		line_h;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	t_img	*tex;
}	t_draw;

typedef struct s_keys
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		left;
	int		right;
}	t_keys;

typedef struct s_bonus	t_bonus;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			win_w;
	int			win_h;
	t_img		frame;
	t_tex		tex[4];
	t_color		floor;
	t_color		ceil;
	t_map		map;
	t_player	player;
	t_keys		keys;
	double		move_speed;
	double		rot_speed;
	long		last_time;
	t_bonus		*bonus;
}	t_game;

void	ft_error(char *message);
void	cub_error(char *msg);
void	game_error(t_game *game, char *msg);
void	*safe_malloc(size_t size);
int		ft_printf(const char *format, ...);
void	free_lines(char **lines, int count);

int		parse_cub(t_game *game, char *path);
int		parse_elements(t_game *game, char *line);
int		parse_color_line(t_color *color, char *line);
int		parse_texture_line(char **path, char *line);
int		has_cub_ext(char *path);
int		is_blank_line(char *line);
int		is_map_line(char *line);
char	*strip_newline(char *line);
void	map_store_line(char ***lines, int *count, char *line);
int		map_build(t_game *game, char **lines, int count);
int		map_validate(t_game *game);
int		map_is_closed(t_game *game);

void	init_game(t_game *game);
int		init_mlx(t_game *game);
void	init_player(t_game *game);
int		load_textures(t_game *game);

int		game_loop(t_game *game);
void	render_frame(t_game *game);
void	raycast_column(t_game *game, int x);
int		select_texture(t_ray *ray);
void	raycast_draw_column(t_game *game, t_ray *ray, int x);
void	draw_background(t_game *game);

int		key_press(int key, t_game *game);
int		key_release(int key, t_game *game);
int		close_window(t_game *game);
void	handle_move(t_game *game);

long	time_ms(void);

void	img_put_pixel(t_img *img, int x, int y, int color);
int		img_get_pixel(t_img *img, int x, int y);
int		color_rgb(int r, int g, int b);

void	free_game(t_game *game);
void	free_map(t_map *map);

int		is_walkable(t_game *game, double x, double y);
void	rotate_player(t_player *p, double angle);

void	bonus_init(t_game *game);
void	bonus_setup_hooks(t_game *game);
void	bonus_destroy(t_game *game);
void	bonus_render(t_game *game);
void	bonus_key_press(int key, t_game *game);
void	bonus_key_release(int key, t_game *game);
int		bonus_is_door_hit(t_game *game, int x, int y);
t_img	*bonus_select_tex(t_game *game, t_ray *ray, t_img *base);
void	bonus_store_zbuffer(t_game *game, int x, double dist);
int		bonus_is_map_char(char c);

#endif
