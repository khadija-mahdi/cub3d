/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:28:36 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/11 12:25:56 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REYCASTING_H
# define REYCASTING_H

# include "../cub3d.h"

# define TILE_SIZE 64

# define WIDTH 1280
# define HEIGHT 768

# define RIGHT 124
# define LEFT 123
# define DOWN 125
# define UP 126
# define ESC 53
# define P_SIZ 8 

# define PLAYER_SPEED 5.5f
# define PLAYER_ROTATION 5.0f

typedef struct s_player
{
	float	rotation_angle;
	float	walk_speed;
	float 	turn_speed;
	
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
	int				player_x;
	int				player_y;
	int				is_player;
	t_img 			*img;
	float 			player_rotation;
	float			player_speed;
	struct s_map	*map;

}				t_data;



void	read_map(struct s_map *map, char *s);
struct s_map	*init_map(struct s_map *map, char *s);
void	init_pos(t_data *data);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	free_list(char **list);
void	exit_msg(char *msg, int status);
int		exit_program(int key_code);
t_data	*init_data(t_data *data,struct s_map  *map);
int		key_code(int key_code, t_data *data);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_2d_map(t_data *data);
void	draw_player(t_data *data, int i, int j);


#endif