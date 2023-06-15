/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:28:36 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/15 18:54:51 by kmahdi           ###   ########.fr       */
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

# define RIGHT_ARROW 124
# define LEFT_ARROW 123
# define DOWN_ARROW 125
# define UP_ARROW 126

# define S_DOWN 1
# define W_UP 13
# define A_LEFT 0
# define D_RIGHT 2

#define MOVE_SPEED 10
#define ROTATION_SPEED 0.5


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

typedef struct s_data {
	void			*mlx_ptr;
	void			*win_ptr;
	t_player		player;
	t_img 			*img;
	struct s_map_info	*map;

}				t_data;

void	free_list(char **list);
void	exit_msg(char *msg, int status);
int		exit_program(int key_code);
t_data	*init_data(t_data *data, struct s_map_info  *map);
int		key_code(int key_code, t_data *data);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_2d_map(t_data *data);
void	rey_casting(struct s_map_info *map);


#endif