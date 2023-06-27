/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:28:36 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/27 21:50:29 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REYCASTING_H
# define REYCASTING_H


# include "../cub3d.h"
# define WIDTH 1800
# define HEIGHT 1000
#define MINI_MAP_WIDTH 200
#define MINI_MAP_HEIGHT 100

# define FOV M_PI / 3

//mouse

#define LEFT_CLICK 1
#define RIGHT_CLICK 2
#define MIDDLE_CLICK 3
#define SCROLL_UP 4
#define SCROLL_DOWN 5

// size 
# define TILE_SIZE 64
# define M_TILE_SIZE 16
# define PLAYER_SIZE 8

# define ESC 53

# define ON_KEYDOWN 2
# define ON_KEYUP 3

# define RIGHT_ARROW 124
# define LEFT_ARROW 123
# define DOWN_ARROW 125
# define UP_ARROW 126

# define S_DOWN 1
# define W_UP 13
# define A_LEFT 0
# define D_RIGHT 2

#define MOVE_SPEED 5
#define ROTATION_SPEED 0.05


typedef struct s_hor_rey {
	double	intersect_y;
	double	intersect_x;
	double	step_y;
	double	step_x;
	double 	wall_x;
	double 	wall_y;
	double	next_y;
	double	next_x;
	int		is_wall;
	double	distance;
}				t_hor_rey;

typedef struct s_ver_rey 
{
	double	intersect_y;
	double	intersect_x;
	double	step_y;
	double	step_x;
	int		is_wall;
	double	wall_x;
	double	wall_y;
	double	next_y;
	double	next_x;
	double distance;

}				t_ver_rey;

typedef struct s_rey {
	double	ray_angle;
	double	wall_x;
	double	wall_y;
	double	distance;
	int		facing_up;
	int		facing_down;
	int		facing_left;
	int		facing_right;
	t_hor_rey	hor_ray;
	t_ver_rey	ver_ray;
}				t_rey;

typedef struct s_player {
	double			player_x;
	double			player_y;
	double			player_rotation;
	double			rotation_angle;
	double			player_speed;
	double			player_direction;
	double			speed_movement;
	double			speed_rotation;
	double			dpx;
	double			dpy;
	
}				t_player;


typedef struct	s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_mini_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mini_img;
typedef struct s_data {
	void				*mlx_ptr;
	void				*win_ptr;
	t_player			player;
	t_img 				*img;
	t_mini_img 			*mini_img;
	struct s_map_info	*map;
	int					dir_keys[3];
	int					dir_mouse[2];
	t_rey				**rays;
	int					wall_nbr;	

}				t_data;

void	free_list(char **list);
void	exit_msg(char *msg, int status);
int		exit_program(int key_code);
t_data	*init_data(t_data *data, struct s_map_info  *map);
int		key_code_fun(int key_code, t_data *data);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_2d_map(t_data *data);
void	rey_casting(struct s_map_info *map);
void	render_player(t_data *data);
int		key_code(t_data *data);
int		key_press(int key_code, t_data *data);
void	player_pos(t_data *data);
int		key_release(int key_code,t_data *data);
void	player_up_down(t_data *data, int key);
void	player_left_right(t_data *data, int key);
int		right_player(t_data *data);
int		down_player(t_data *data);
int		up_player(t_data *data);
int		left_player(t_data *data);
int		wall_collision(t_data *data, double y, double x);
void	cast_rays(t_data *data);
double	normalize_angle(double angle);
void	vertical_ray(t_data *data, t_rey *rays, double angle);
void	horizontal_ray(t_data *data, t_rey *rays, double angle);
int		hit_wall(t_data *data, double y, double x);
void	get_directions(t_rey *rays, double angle);
void	draw_line(t_data *data, int y_start, int x_start, int end_y , int end_x, int clr);
void draw_mini_map(t_data *data);
#endif