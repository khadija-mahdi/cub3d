/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:28:36 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/18 19:31:36 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REYCASTING_H
# define REYCASTING_H

# include "../cub3d.h"

# define PI 3.14159265359

# define TILE_SIZE 64
# define PLAYER_SIZE 8

# define WIDTH 1280
# define HEIGHT 768

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
#define COLLISION_DIS 16

#define MOVE_SPEED 3
#define ROTATION_SPEED 0.1


typedef struct s_player {
	double			player_x;
	double				player_y;
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

typedef struct s_keys
{
	int	right_arrow;
	int	left_arrow;
	int	right_key;
	int	left_key;
	int	up_key;
	int	down_key;

}			t_keys;

typedef struct s_data {
	void			*mlx_ptr;
	void			*win_ptr;
	t_player		player;
	t_img 			*img;
	struct s_map_info	*map;
	int					dir_keys[3];
	t_keys				keys;

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
int		keys_up(int key_code, t_data *data);
void	player_pos(t_data *data);
int		keys_down(int key_code,t_data *data);
void	player_up_down(t_data *data, int key);
void	player_left_right(t_data *data, int key);


#endif